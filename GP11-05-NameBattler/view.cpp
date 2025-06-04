#include <iostream>
#include "view.h"

#include "Character.h"

namespace view
{
    namespace character
    {
        void show_profile(const Character& character)
        {
            Ability ability =  character.get_ability();
            
            std::cout << " 名前 ： " << character.get_name() << "\n";
            std::cout << "\n [ 能力値 ]\n";
            std::cout << "  体力　： " << ability.hp << "\n";
            std::cout << "  攻撃　： " << ability.attack << "\n";
            std::cout << "  防御　： " << ability.defense << "\n";
            std::cout << "  速度　： " << ability.speed << "\n";
            std::cout << "==============================\n\n";
        }
    }

    namespace menu
    {
        void show_main_menu()
        {
            std::cout << "==============================\n";
            std::cout << "        ネームバトラー        \n";
            std::cout << "==============================\n";
            std::cout << "\n";
            std::cout << " 1. キャラ召喚\n";
            std::cout << " 2. 二人で遊ぶ\n";
            std::cout << " 3. AI対戦\n";
            std::cout << " 9. ゲーム終了\n";
            std::cout << "\n";
            std::cout << "==============================\n";
            std::cout << "選択してください（1/2/3/9）: ";
        }
        void hint_back_to_menu()
        {
            std::cout << "何かキーを押すとメニューに戻ります…\n";
        }
        
        void show_summon_title()
        {
            std::cout << "------------------------------\n";
            std::cout << "          キャラ召喚          \n";
            std::cout << "------------------------------\n";
        }
        void show_summon_profile_title()
        {
            std::cout << "==============================\n";
            std::cout << "        キャラプロフィール     \n";
            std::cout << "==============================\n";
        }
    }
}
