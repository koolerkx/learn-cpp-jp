/**
 * @file    view.h
 * @brief   画面表示と出力管理
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef VIEW_H
#define VIEW_H
#include <vector>

#include "Battle.h"
#include "Card.h"
#include "Hero.h"

/**
 * @namespace    view
 * @brief        出力メッセージ
 */
namespace view
{
    namespace hero
    {
        void show_profile(const Hero& hero);
        void show_list(const Hero* hero, int count);
        void show_cards(const std::vector<std::unique_ptr<Card>>& cards);
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
            void battle_p2p_title();
            void battle_p2c_title();
            void battle_c2c_title();

            void player_select_hero(const char* label);
            void select_hero_options();

            void battle_start_title();
            void battle_round(int round);
            void battle_round_hero_list(PlayerHero** heroes, int from);
            void battle_round_hero(const PlayerHero& player_round);

            void battle_round_option_message();

            void battle_card_list(const std::vector<const Card*>& cards);

            void dice_result(dice::DiceResult dice, dice::DiceYakuResult yaku);

            void action_description(const PlayerHero& ph, const Card* card);
            void attack_action_description(const PlayerHero& from, const PlayerHero& to);

            void attack_result(const PlayerHero& to, const int power);
            void heal_result(const PlayerHero& to, const int power);
            void defense_result(const PlayerHero& to, const int power);

            void defender_dead_message(const PlayerHero& hero);
            void round_exceed();

            void show_experience_gain(int exp, int total_exp, int level, const char* name);
            void show_level_up(int new_level);

            void end_message();
        }

        namespace battle_tower
        {
            void title();
            void next_level_title(int next_level);
            void end_message(int final_level);
            void end_message_cleared(int final_level);
        }
    }

    // text output for info user
    namespace message
    {
        void press_any_key_menu();
        void press_any_key_continue();

        namespace input
        {
            void retry();
        }
    }

    namespace format_line
    {
        void blank();
        void block();
        void single_line();
        void double_line();
    }
}

#endif // VIEW_H