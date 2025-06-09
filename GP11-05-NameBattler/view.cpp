#include <iostream>
#include "view.h"

#include <vector>

#include "Battle.h"
#include "Card.h"
#include "Hero.h"
#include "utils.h"

namespace view
{
    namespace hero
    {
        void show_profile(const Hero& hero)
        {
            Ability ability = hero.get_ability();

            std::cout << " 名前 ： " << hero.get_name() << "\n";
            std::cout << "\n [ 能力値 ]\n";
            std::cout << "  体力　： " << ability.hp << "\n";
            std::cout << "  攻撃　： " << ability.attack << "\n";
            std::cout << "  防御　： " << ability.defense << "\n";
            std::cout << "  速度　： " << ability.speed << "\n\n";

            show_cards(hero.get_cards());
        }

        void show_list(const Hero* heroes, int count)
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << i + 1 << ": " << heroes[i].get_name() << " (" << heroes[i].get_rate() << ")\n";
            }
        }

        void show_cards(const std::vector<std::unique_ptr<Card>>& cards)
        {
            std::cout << "［　所持カード　］\n";

            for (int i = 0; i < static_cast<int>(cards.size()); i++)
            {
                std::cout << i + 1 << ". " << cards[i]->get_label() << " (効果：" << cards[i]->get_power() << ")\n";
            }

            std::cout << "==============================\n";
        }
    }

    namespace flow
    {
        namespace menu
        {
            void show_main_menu()
            {
                std::cout << "\n==============================\n";
                std::cout << "        ネームバトラー        \n";
                std::cout << "==============================\n";
                std::cout << "\n";
                std::cout << " 1. 英雄召喚\n";
                std::cout << " 2. 二人で遊ぶ\n";
                std::cout << " 3. AI対戦\n";
                std::cout << " 4. 英雄管理\n";
                std::cout << " 9. ゲーム終了\n";
                std::cout << "\n";
                std::cout << "==============================\n";
            }

            void option_message()
            {
                std::cout << "選択してください（1/2/3/4/9）: ";
            }

            void game_end_message()
            {
                std::cout << "またいっしょに遊ぼう！\n";
                std::cout << "作者：\n";
            }
        }

        namespace summon
        {
            void title()
            {
                std::cout << "\n------------------------------\n";
                std::cout << "             英雄召喚          \n";
                std::cout << "------------------------------\n";
            }

            void profile_title()
            {
                std::cout << "\n==============================\n";
                std::cout << "        英雄プロフィール        \n";
                std::cout << "==============================\n";
            }

            void name_input_message()
            {
                std::cout << "英雄の名前を呼んでください：";
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
                std::cout << "\n結果：『" << name << "』が成功に召喚された！\n";
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

        namespace hero
        {
            void hero_management_menu()
            {
                std::cout << "\n==============================\n";
                std::cout << "       所持英雄管理メニュー\n";
                std::cout << "==============================\n\n";
                std::cout << " 1. 一覧（名前と評価）\n";
                std::cout << " 2. 詳細を見る\n";
                std::cout << " 3. 英雄を削除\n";
                std::cout << " 9. メインメニューに戻る\n\n";
                std::cout << "==============================\n";
            }

            void hero_menu_option_message()
            {
                std::cout << "選択してください（1/2/3/9）: ";
            }

            void hero_list_title()
            {
                std::cout << "\n------------------------------\n";
                std::cout << "          所持英雄一覧          \n";
                std::cout << "------------------------------\n";
            }

            void hero_detail_title()
            {
                std::cout << "\n==============================\n";
                std::cout << "         英雄の詳細情報         \n";
                std::cout << "==============================\n";
            }

            void hero_detail_option_message()
            {
                std::cout << "詳細を見たい英雄の番号を入力してください：";
            }

            void hero_delete_title()
            {
                std::cout << "\n------------------------------\n";
                std::cout << "           お別れ             \n";
                std::cout << "------------------------------\n";
            }

            void hero_delete_option_message()
            {
                std::cout << "お別れする英雄の番号を選んでください：";
            }

            void hero_delete_result_message(const char* name)
            {
                std::cout << "あなたの手を離れ、『" << name << "』は旅立ちました。\n\n";
            }
        }

        namespace battle
        {
            void player_select_hero(const char* label)
            {
                std::cout << "\n" << label << "の選択\n";
            }

            void select_hero_options()
            {
                std::cout << "英雄の番号を入力してください：";
            }

            void battle_title()
            {
                std::cout << "------------------------------" << "\n";
                std::cout << "         バトル開始！" << "\n";
                std::cout << "------------------------------" << "\n\n";
            }

            void battle_round(const int round)
            {
                std::cout << "【ラウンド " << round << "】";
            }

            void battle_round_hero_list(const std::vector<std::unique_ptr<PlayerHero>>& heroes, const int size)
            {
                std::cout << "行動順：\n";
                for (int i = 0; i < size; i++)
                {
                    std::cout << i + 1 << " : (" << heroes[i]->get_player_label() << ") ";
                    std::cout << heroes[i]->get_name();
                    std::cout << " (HP: " << heroes[i]->get_hp() << "/" << heroes[i]->get_max_hp() << ", 防御値: " <<
                        heroes[i]->get_shield() << ")\n";
                }
                std::cout << "\n";
            }

            void battle_round_hero(const PlayerHero& player_round)
            {
                std::cout << "> 現在のターン：";
                std::cout << "(" << player_round.get_player_label() << ")　";
                std::cout << player_round.get_name();
                std::cout << "\n\n";
            }

            void battle_round_attack_option_list(const std::vector<const Card*>& cards)
            {
                std::cout << "ーー アクションカードを選んでください ーー\n";

                for (int i = 0; i < static_cast<int>(cards.size()); i++)
                {
                    std::cout << i + 1 << ". " << cards[i]->get_label() << " (効果：" << cards[i]->get_power() << ")\n";
                }

                std::cout << "\n";
            }

            void battle_round_option_message()
            {
                std::cout << "選択：";
            }

            void dice_result(const int dice)
            {
                std::cout << "> " << " サイコロ結果 (1d" << Battle::DICE_UPPER << ")：" << dice << "\n";
            }

            void action_description(const PlayerHero& ph, const Card* card)
            {
                std::cout << "> " << ph.get_name() << " は　" << card->get_label() << "を使いました\n\n";
            }

            void attack_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " は " << power << " ダメージを受けた（残り HP：" << to.get_hp() << "）\n\n";
            }

            void heal_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " は " << power << " HP回復した（残り HP：" << to.get_hp() << "）\n\n";
            }

            void defense_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " は " << power << " のシールドを得た（防御：" << to.get_shield() << "）\n\n";
            }

            void defender_dead_message(const PlayerHero& hero)
            {
                std::cout << "> " << hero.get_name() << " は 戦いの場に倒れた...\n\n";
            }

            void end_message()
            {
                std::cout << "対戦終了\n";
                std::cout << "メニューに戻る\n";
            }
        }
    }

    namespace message
    {
        void press_any_key_menu()
        {
            std::cout << "何かキーを押すとメニューに戻ります…\n";
        }

        void press_any_key_continue()
        {
            std::cout << "何かキーを押すと続く…\n";
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
            std::cout << "\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n";
        }

        void show_double_line()
        {
            std::cout << "\n==============================\n";
        }
    }
}
