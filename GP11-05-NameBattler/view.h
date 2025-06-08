#pragma once
#include <vector>

#include "Battle.h"
#include "Card.h"
#include "Hero.h"

namespace view
{
    namespace hero
    {
        void show_profile(const Hero& hero);
        void show_list(const Hero* hero, int count);
    }

    // text output for main flow
    namespace flow
    {
        namespace menu
        {
            void show_main_menu();
            void option_message();
            void game_end_message();
        }

        namespace summon
        {
            void title();
            void profile_title();
            void name_input_message();
            void saving_menu();
            void saving_menu_option_message();
            void result_message(const char* name);
        }

        namespace initialize_save
        {
            void welcome_message();
            void end_message();
            void save_data_not_found_message();
        }

        namespace hero
        {
            void hero_management_menu();
            void hero_menu_option_message();

            void hero_list_title();

            void hero_detail_title();
            void hero_detail_option_message();

            void hero_delete_title();
            void hero_delete_option_message();
            void hero_delete_result_message(const char* name);

            void hero_not_found_message();
        }

        namespace battle
        {
            void player_select_hero(const char* label);
            void select_hero_options();

            void battle_title();
            void battle_round(int round);
            void battle_round_hero_list(PlayerHero* const* heroes, const int size);
            void battle_round_hero(const PlayerHero& player_round);

            void battle_round_option_message();

            void battle_round_attack_option_list(const std::vector<const Card*>& cards);

            void attack_action_description(const PlayerHero& from, const PlayerHero& to);

            void attack_damage_result(const char hero_name[Hero::NAME_MAX_LENGTH], int damage, int remaining_hp);

            void defender_dead_message(const PlayerHero& hero);

            void end_message();
        }
    }

    // text output for info user
    namespace message
    {
        void press_any_key();

        namespace input
        {
            void retry();
        }
    }

    namespace format_line
    {
        void show_block_separator();
    }
}
