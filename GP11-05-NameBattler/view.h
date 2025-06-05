#pragma once
#include "Character.h"

namespace view
{
    namespace character
    {
        void show_profile(const Character& character);
    }

    // text output for main flow
    namespace flow
    {
        namespace menu
        {
            void show_main_menu();
            void end_message();
        }
        namespace summon
        {
            void title();
            void profile_title();
            void name_input_message();
            void saving_menu();
            void result_message(const char& name);
        }
        namespace initialize_save
        {
            void welcome_message();
            void end_message();
            void save_data_not_found_message();
        }
    }

    // text output for info user
    namespace message
    {
        void key_back_to_menu_message();
    }

    namespace format_line
    {
        void show_block_separator();
    }
}