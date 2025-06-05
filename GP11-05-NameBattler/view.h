#pragma once
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