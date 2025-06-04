#pragma once
#include "Character.h"

namespace view
{
    namespace character
    {
        void show_profile(const Character& character);
    }

    namespace menu
    {
        void show_main_menu();
        void hint_back_to_menu();
        
        void show_summon_title();
        void show_summon_profile_title();
    }
}