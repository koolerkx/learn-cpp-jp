#include "Battle.h"

#include <iostream>
#include "view.h"
#include "utils.h"

Battle::Battle(PlayerHero* p1, PlayerHero* p2)
{
    heroes_[0] = p1;
    heroes_[1] = p2;
}

bool Battle::run()
{
    start();
    while (update())
    {
        // TODO: extract
        view::message::press_any_key_continue();
        std::cin.get();
        view::format_line::double_line();
    }
    end();

    // HACK: ¡‚ÌÝŒv‚ÅAŸŽÒ‚Í•K‚¸attacker‚Å‚ ‚é
    // return is_win
    return heroes_[attacker_index()]->type == PLAYER_HERO_TYPE::PLAYER;
}

void Battle::start()
{
    view::flow::battle::battle_start_title();
}

bool Battle::update()
{
    advance_round();
    execute_round();
    return is_continue_round();
}

void Battle::advance_round()
{
    view::flow::battle::battle_round(round_++);
    view::flow::battle::battle_round_hero_list(heroes_, round_);
    view::flow::battle::battle_round_hero(*heroes_[attacker_index()]);
}

void Battle::execute_round()
{
    int attacker_i = attacker_index();
    int defender_i = defender_index();
    PlayerHero& attacker = *heroes_[attacker_i];
    PlayerHero& defender = *heroes_[defender_i];

    const Card* selected_card = handle_card_select(attacker);

    // int dice = utils::random(dice::DICE_LOWER, dice::DICE_UPPER);
    // float multiply = Battle::offset_dice_multiplier(dice);
    dice::DiceResult dice_result = dice::draw_dice();
    dice::DiceYakuResult yaku_result = dice::dice_multiply(dice_result);

    const int power = selected_card->apply_card(attacker, defender, yaku_result.multiplier);

    view::flow::battle::action_description(attacker, selected_card);
    view::flow::battle::dice_result(dice_result, yaku_result);
    view::format_line::blank();

    selected_card->result_message(attacker, defender, power);
}

bool Battle::is_continue_round()
{
    return heroes_[attacker_index()]->get_hp() > 0 && heroes_[defender_index()]->get_hp() > 0;
}

void Battle::end()
{
    view::flow::battle::defender_dead_message(*heroes_[defender_index()]);

    for (PlayerHero* hero : heroes_)
    {
        if (hero->type == PLAYER_HERO_TYPE::COM) { continue; }

        int level_before = hero_level::get_level(hero->get_experience());
        int exp_to_gain = hero_level::get_expected_experience_for_battle(level_before);
        hero->gain_experience(exp_to_gain);

        int level_after = hero_level::get_level(hero->get_experience());
        view::flow::battle::show_experience_gain(exp_to_gain, hero->get_experience(), level_after, hero->get_name());
        view::format_line::blank();

        if (level_after > level_before)
        {
            view::flow::battle::show_level_up(level_after);
            view::format_line::blank();
        }
        
        view::message::press_any_key_continue();
        std::cin.get();
    }
}

float Battle::offset_dice_multiplier(int dice_value)
{
    static constexpr float MULTIPLIER_LOWER = 0.9f;
    static constexpr float MULTIPLIER_UPPER = 1.3f;

    return MULTIPLIER_LOWER +
    (static_cast<float>(dice_value - dice::DICE_LOWER) *
        (MULTIPLIER_UPPER - MULTIPLIER_LOWER)) / static_cast<float>(dice::DICE_UPPER - dice::DICE_LOWER);
}

const Card* Battle::handle_card_select(const PlayerHero& ph)
{
    view::flow::battle::battle_card_list(ph.get_available_cards());

    return ph.select_card();
}

namespace dice
{
    YakuSet yaku_sets[] = {
        {
            YAKU::PINZORO,
            2.0f,
            [](DiceResult r) { return r.dice_1 == 1 && r.dice_2 == 1 && r.dice_3 == 1; },
        },
        {
            YAKU::ARASHI,
            1.4f,
            [](DiceResult r) { return r.dice_1 != 1 && r.dice_1 == r.dice_2 && r.dice_2 == r.dice_3; },
        },
        {
            YAKU::SHIGORO,
            1.1f,
            [](DiceResult r) { return r.dice_1 == 4 && r.dice_2 == 5 && r.dice_3 == 6; },
        },
        {
            YAKU::TUJYOU,
            1.0f,
            [](DiceResult r) { return r.dice_1 == r.dice_2 || r.dice_2 == r.dice_3; },
        },
        {
            YAKU::HIFUMI,
            0.0f,
            [](DiceResult r) { return r.dice_1 == 1 && r.dice_2 == 2 && r.dice_3 == 3; },
        },
        {
            YAKU::OTHER,
            0.0f,
            [](DiceResult) { return true; },
        }
    };
    extern const int yaku_sets_count = std::size(yaku_sets);
    
    DiceResult draw_dice()
    {
        srand(static_cast<unsigned>(time(nullptr)));
        return {
            utils::random(dice::DICE_LOWER, dice::DICE_UPPER),
            utils::random(dice::DICE_LOWER, dice::DICE_UPPER),
            utils::random(dice::DICE_LOWER, dice::DICE_UPPER),
        };
    }

    DiceYakuResult dice_multiply(DiceResult dice_state)
    {
        // HACK: ®—ñ
        if (dice_state.dice_1 > dice_state.dice_3)
        {
            std::swap(dice_state.dice_1, dice_state.dice_3);
        }
        if (dice_state.dice_1 > dice_state.dice_2)
        {
            std::swap(dice_state.dice_1, dice_state.dice_2);
        }

        for (YakuSet yaku_set: yaku_sets)
        {
            if (yaku_set.test(dice_state))
            {
                DiceYakuResult result = {yaku_set.yaku, yaku_set.multiplier};
                return result;
            }
        }

        return { YAKU::OTHER, 0};
    }
}
