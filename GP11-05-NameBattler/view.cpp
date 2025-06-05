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

    namespace flow
    {
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
            }

            void option_message()
            {
                std::cout << "選択してください（1/2/3/9）: ";
            }

            void game_end_message()
            {
                std::cout << "Game End" << "\n";
            }
        }
        
        namespace summon
        {
            void title()
            {
                std::cout << "------------------------------\n";
                std::cout << "          キャラ召喚          \n";
                std::cout << "------------------------------\n";
            }
            
            void profile_title()
            {
                std::cout << "==============================\n";
                std::cout << "        キャラプロフィール     \n";
                std::cout << "==============================\n";
            }

            void name_input_message()
            {
                std::cout << "キャラの名前を呼んでください：";
            }
            
            void saving_menu()
            {
                std::cout << "保存しますか？ \n";
                std::cout << "1. はい \n";
                std::cout << "2. いいえ \n\n";
            }

            void saving_menu_option_message()
            {
                std::cout << "選択してください（1/2）: ";
            }
            
            void result_message(const char* name)
            {
                std::cout << "\n結果：『" << name << "』が成功に召喚された！\n\n";
            }

        }

        namespace initialize_save
        {
            void welcome_message()
            {
                std::cout << "==============================\n";
                std::cout << "ようこそ、ネームバトラーの世界へ！\n";
                std::cout << "==============================\n\n";
            }
            
            void end_message()
            {
                std::cout << "では、ネームバトラーマスターを目指して、頑張りましょう！\n";
            }
            
            void save_data_not_found_message()
            {
                std::cout << "セーブデータは見つからなかった\n";
                std::cout << "新しいデータを作る\n";
                std::cout << "\n";
            }
        }
    }

    namespace message
    {
        void press_any_key()
        {
            std::cout << "何かキーを押すとメニューに戻ります…\n";
        }

        namespace input
        {
            void retry()
            {
                std::cout << "無効な入力です。もう一度入力してください。\n\n";
            }
        }
    }

    namespace format_line
    {
        void show_block_separator()
        {
            std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n";
        }
    }
}
