#include "Battle.h"

#include <iostream>
#include "view.h"
#include "utils.h"

Battle::Battle(Player* p1, Player* p2)
{
    hero_order_.emplace_back(std::make_unique<PlayerHero>(p1, p1->get_hero()));
    hero_order_.emplace_back(std::make_unique<PlayerHero>(p2, p2->get_hero()));
}

void Battle::start()
{
    view::flow::battle::battle_title();

    int round = 1;

    while (true)
    {
        view::flow::battle::battle_round(round++);
        view::flow::battle::battle_round_hero_list(hero_order_);

        PlayerHero& attacker = *hero_order_[current_order];
        current_order = (current_order + 1) % hero_order_.size();
        PlayerHero& defender = *hero_order_[current_order];

        view::flow::battle::battle_round_hero(attacker);

        view::flow::battle::battle_round_attack_option_list(attacker.get_available_cards());

        int attacker_selected = utils::input::validated_input(
            utils::input::validator::is_in_range(1, static_cast<int>(attacker.get_available_cards().size())),
            view::flow::battle::battle_round_option_message
        );
        const Card* attacker_selected_card = attacker.get_card(attacker_selected - 1);

        int dice = utils::random(Battle::DICE_LOWER, Battle::DICE_UPPER);
        float multiply = Battle::offset_dice_multiplier(dice);

        const int power = attacker_selected_card->apply_card(attacker, defender, multiply);

        view::flow::battle::action_description(attacker, attacker_selected_card);
        view::flow::battle::dice_result(dice);

        attacker_selected_card->result_message(attacker, defender, power);

        if (defender.get_hp() <= 0)
        {
            view::flow::battle::defender_dead_message(defender);
            break;
        }
        
        view::message::press_any_key_continue();
        std::cin.get();
        view::format_line::show_double_line();
    }

    view::flow::battle::end_message();
    view::message::press_any_key_menu();
    std::cin.get();
}

float Battle::offset_dice_multiplier(int dice_value)
{
    return (static_cast<float>(dice_value) - static_cast<float>(Battle::DICE_BASE)) / static_cast<float>(
        Battle::DICE_BASE);
}
