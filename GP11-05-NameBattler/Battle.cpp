#include "Battle.h"

#include <iostream>
#include "view.h"
#include "utils.h"

Battle::Battle(Player* p1, Player* p2)
{
    const std::function<std::unique_ptr<PlayerHero>(Player*)> make_hero = [](Player* player) {
        return player->is_ai() ? 
            std::make_unique<PlayerHeroAI>(player, player->get_hero()) :
            std::make_unique<PlayerHero>(player, player->get_hero());
    };
    
    hero_order_.emplace_back(make_hero(p1));
    hero_order_.emplace_back(make_hero(p2));
}

void Battle::start()
{
    view::flow::battle::battle_start_title();

    int round = 1;

    while (true)
    {
        view::flow::battle::battle_round(round++);
        view::flow::battle::battle_round_hero_list(hero_order_);

        PlayerHero& attacker = *hero_order_[current_order];
        current_order = (current_order + 1) % hero_order_.size();
        PlayerHero& defender = *hero_order_[current_order];

        view::flow::battle::battle_round_hero(attacker);
        
        const Card* selected_card = handle_card_select(attacker);
        
        int dice = utils::random(Battle::DICE_LOWER, Battle::DICE_UPPER);
        float multiply = Battle::offset_dice_multiplier(dice);
    
        const int power = selected_card->apply_card(attacker, defender, multiply);

        view::flow::battle::action_description(attacker, selected_card);
        view::flow::battle::dice_result(dice);

        selected_card->result_message(attacker, defender, power);

        if (defender.get_hp() <= 0)
        {
            view::flow::battle::defender_dead_message(defender);
            break;
        }

        view::message::press_any_key_continue();
        std::cin.get();
        view::format_line::double_line();
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

const Card* Battle::handle_card_select(const PlayerHero& ph)
{
    view::flow::battle::battle_card_list(ph.get_available_cards());
    
    return ph.select_card();
}

