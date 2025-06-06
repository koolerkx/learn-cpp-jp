#include "Battle.h"

#include <iostream>
#include "view.h"

Battle::Battle(Player* p1, Player* p2)
{
    const PlayerHero ph1 = PlayerHero(p1, p1->get_hero());
    const PlayerHero ph2 = PlayerHero(p2, p2->get_hero());

    PlayerHero phs[] = {ph1, ph2};
    hero_order = phs;
    hero_order_size = std::size(phs);
}

void Battle::start()
{
    view::flow::battle::battle_title();

    int round = 1;

    while (true)
    {
        view::flow::battle::battle_round(round++);
        view::flow::battle::battle_round_hero_list(hero_order, hero_order_size);

        PlayerHero attacker = hero_order[current_order];
        current_order = (current_order + 1) % hero_order_size;
        PlayerHero defender = hero_order[current_order];

        view::flow::battle::battle_round_hero(attacker);

        view::flow::battle::battle_round_attack_option_list(attacker.get_available_cards(),
                                                            attacker.available_cards_size);

        int attacker_selected = utils::input::validated_input(
            utils::input::validator::is_in_range(1, attacker.available_cards_size),
            view::flow::battle::battle_round_option_message
        );
        Card* attacker_selected_card = attacker.get_card(attacker_selected - 1);

        int dice = utils::random(Battle::DICE_LOWER, Battle::DICE_UPPER);
        float multiply = Battle::offset_dice_multiplier(dice);

        attacker_selected_card->apply_card(attacker, defender, multiply);

        const int defender_hp_before = defender.get_hp();
        view::flow::battle::attack_action_description(attacker, defender);
        view::flow::battle::attack_damage_result(defender.get_name(), defender_hp_before, defender.get_hp());

        if (defender.get_hp() <= 0)
        {
            break;
        }

        view::flow::battle::end_message();
        view::message::press_any_key();
        std::cin.get();
    }
}

float Battle::offset_dice_multiplier(int dice_value)
{
    return static_cast<float>(dice_value) - static_cast<float>(Battle::DICE_BASE) / static_cast<float>(
        Battle::DICE_BASE);
}
