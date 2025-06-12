/**
 * @file    view.cpp
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#include <iostream>
#include "view.h"

#include <vector>

#include "Battle.h"
#include "Card.h"
#include "Hero.h"

namespace view
{
    namespace hero
    {
        void show_profile(const Hero& hero)
        {
            int exp = hero.get_experience();
            int level = hero_level::get_level(exp);
            Ability ability = hero.get_scaled_ability();

            std::cout << " ���O �F " << hero.get_name() << "\n";
            std::cout << "\n [ �\�͒l ]\n";
            std::cout << "  �̗́@�F " << ability.hp << "\n";
            std::cout << "  �U���@�F " << ability.attack << "\n";
            std::cout << "  �h��@�F " << ability.defense << "\n";
            view::format_line::blank();

            std::cout << "  ���x���F " << level << " (�݌v�o���l�F" << exp << ")\n";
            std::cout << "  �ő僌�x���̑��]���F " << hero.get_rate() << "\n";
            view::format_line::blank();

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
            std::cout << "�m�@�����J�[�h�@�n\n";

            for (int i = 0; i < static_cast<int>(cards.size()); i++)
            {
                std::cout << i + 1 << ". " << cards[i]->get_label() << " (���ʁF" << cards[i]->get_power() << ")\n";
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
                std::cout << "        �l�[���o�g���[        \n";
                std::cout << "==============================\n";
                std::cout << "\n";
                std::cout << " 1. �p�Y����\n";
                std::cout << " 2. ��l�őΐ�\n";
                std::cout << " 3. COM�Ƒΐ�\n";
                std::cout << " 4. COM�ΐ�V�~�����[�V����\n";
                std::cout << " 5. �o�g���^���[\n";
                std::cout << " 6. �p�Y�Ǘ�\n";
                std::cout << " 9. �Q�[���I��\n";
                format_line::blank();
            }

            void option_message()
            {
                std::cout << "�I�����Ă��������i1/2/3/4/9�j: ";
            }

            void game_end_message()
            {
                std::cout << "�܂���������ɗV�ڂ��I\n";
                std::cout << "��ҁF\n";
            }
        }

        namespace summon
        {
            void title()
            {
                std::cout << "------------------------------\n";
                std::cout << "             �p�Y����          \n";
                std::cout << "------------------------------\n";
            }

            void profile_title()
            {
                std::cout << "==============================\n";
                std::cout << "        �p�Y�v���t�B�[��        \n";
                std::cout << "==============================\n";
            }

            void name_input_message()
            {
                std::cout << "�p�Y�̖��O���Ă�ł��������F";
            }

            void saving_menu()
            {
                std::cout << "�ۑ����܂����H \n";
                std::cout << "1. �͂� \n";
                std::cout << "2. ������ \n\n";
            }

            void saving_menu_option_message()
            {
                std::cout << "�I�����Ă��������i1/2�j: ";
            }

            void result_message(const char* name)
            {
                std::cout << "���ʁF�w" << name << "�x�������ɏ������ꂽ�I\n";
            }
        }

        namespace initialize_save
        {
            void welcome_message()
            {
                std::cout << "==============================\n";
                std::cout << "�悤�����A�l�[���o�g���[�̐��E�ցI\n";
                std::cout << "==============================\n\n";
            }

            void end_message()
            {
                std::cout << "�ł́A�l�[���o�g���[�}�X�^�[��ڎw���āA�撣��܂��傤�I\n";
            }

            void save_data_not_found_message()
            {
                std::cout << "�Z�[�u�f�[�^�͌�����Ȃ�����\n";
                std::cout << "�V�����f�[�^�����\n";
                std::cout << "\n";
            }
        }

        namespace hero
        {
            void hero_management_menu()
            {
                std::cout << "==============================\n";
                std::cout << "       �����p�Y�Ǘ����j���[\n";
                std::cout << "==============================\n\n";
                std::cout << " 1. �ꗗ�i���O�ƕ]���j\n";
                std::cout << " 2. �ڍׂ�����\n";
                std::cout << " 3. �p�Y���폜\n";
                std::cout << " 9. ���C�����j���[�ɖ߂�\n";
                format_line::blank();
            }

            void hero_menu_option_message()
            {
                std::cout << "�I�����Ă��������i1/2/3/9�j: ";
            }

            void hero_list_title()
            {
                std::cout << "------------------------------\n";
                std::cout << "          �����p�Y�ꗗ          \n";
                std::cout << "------------------------------\n";
            }

            void hero_detail_title()
            {
                std::cout << "==============================\n";
                std::cout << "         �p�Y�̏ڍ׏��         \n";
                std::cout << "==============================\n";
            }

            void hero_detail_option_message()
            {
                std::cout << "�ڍׂ��������p�Y�̔ԍ�����͂��Ă��������F";
            }

            void hero_delete_title()
            {
                std::cout << "------------------------------\n";
                std::cout << "           ���ʂ�             \n";
                std::cout << "------------------------------\n";
            }

            void hero_delete_option_message()
            {
                std::cout << "���ʂꂷ��p�Y�̔ԍ���I��ł��������F";
            }

            void hero_delete_result_message(const char* name)
            {
                std::cout << "���Ȃ��̎�𗣂�A�w" << name << "�x�͗������܂����B\n\n";
            }
        }

        namespace battle
        {
            void battle_p2p_title()
            {
                std::cout << "==============================\n";
                std::cout << "         ��l�ΐ탂�[�h         \n";
                std::cout << "==============================\n";
            }

            void battle_p2c_title()
            {
                std::cout << "==============================\n";
                std::cout << "         COM�ΐ탂�[�h          \n";
                std::cout << "==============================\n";
            }

            void battle_c2c_title()
            {
                std::cout << "==============================\n";
                std::cout << "  �@�@COM�ΐ�V�~�����[�V����      \n";
                std::cout << "==============================\n";
            }

            void player_select_hero(const char* label)
            {
                std::cout << "\n" << label << "�̑I��\n";
            }

            void select_hero_options()
            {
                std::cout << "�p�Y�̔ԍ�����͂��Ă��������F";
            }

            void battle_start_title()
            {
                std::cout << "------------------------------" << "\n";
                std::cout << "         �o�g���J�n�I" << "\n";
                std::cout << "------------------------------" << "\n\n";
            }

            void battle_round(const int round)
            {
                std::cout << "�y���E���h " << round << "�z";
            }

            void battle_round_hero_list(PlayerHero** heroes, int from)
            {
                std::cout << "�s�����F\n";
                for (int i = from; i < from + BATTLE_HEROES; i++)
                {
                    int hero_idx = i % BATTLE_HEROES;
                    std::cout << hero_idx + 1 << " : (" << heroes[hero_idx]->get_player_label() << ") ";
                    std::cout << heroes[hero_idx]->get_name();
                    std::cout << " (HP: " << heroes[hero_idx]->get_hp() << "/" << heroes[hero_idx]->get_max_hp() <<
                        ", �h��l: " <<
                        heroes[hero_idx]->get_shield() << ")\n";
                }
                std::cout << "\n";
            }

            void battle_round_hero(const PlayerHero& player_round)
            {
                std::cout << "> ���݂̃^�[���F";
                std::cout << "(" << player_round.get_player_label() << ")�@";
                std::cout << player_round.get_name();
                std::cout << "\n\n";
            }

            void battle_card_list(const std::vector<const Card*>& cards)
            {
                std::cout << "�[�[ �A�N�V�����J�[�h��I��ł������� �[�[\n";

                for (int i = 0; i < static_cast<int>(cards.size()); i++)
                {
                    std::cout << i + 1 << ". " << cards[i]->get_label() << " (���ʁF" << cards[i]->get_power() << ")\n";
                }

                std::cout << "\n";
            }

            void battle_round_option_message()
            {
                std::cout << "�I���F";
            }

            void dice_result(dice::DiceResult dice, dice::DiceYakuResult yaku)
            {
                std::cout << "> " << " �T�C�R������ (3d" << dice::DICE_UPPER << ")�F" << dice.dice_1 << " " << dice.dice_2 <<
                    " " << dice.dice_3 << "\n";
               
                std::cout << "���F";
                switch (yaku.yaku)
                {
                case dice::YAKU::PINZORO:
                    std::cout << "�s���]���i�{���F�~" << yaku.multiplier << "�j";
                    break;
                case dice::YAKU::ARASHI:
                    std::cout << "�]���ځi�{���F�~" << yaku.multiplier << "�j";
                    break;
                case dice::YAKU::SHIGORO:
                    std::cout << "�V�S���i�{���F�~" << yaku.multiplier << "�j";
                    break;
                case dice::YAKU::TUJYOU:
                    std::cout << "�ʏ���i�{���F�~" << yaku.multiplier << "�j";
                    break;
                case dice::YAKU::HIFUMI:
                    std::cout << "�q�t�~�i�{���F�~" << yaku.multiplier << "�j";
                    break;
                case dice::YAKU::OTHER:
                    std::cout << "���Ȃ��i�{���F�~" << yaku.multiplier << "�j";
                    break;
                default:
                    std::cout << "�s���i�{���F�~" << yaku.multiplier << "�j";
                    break;
                }
                format_line::blank();
            }

            void action_description(const PlayerHero& ph, const Card* card)
            {
                std::cout << "> " << ph.get_name() << " �́@" << card->get_label() << "���g���܂���\n\n";
            }

            void attack_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " �� " << power << " �_���[�W���󂯂��i�c�� HP�F" << to.get_hp() << "�j\n\n";
            }

            void heal_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " �� " << power << " HP�񕜂����i�c�� HP�F" << to.get_hp() << "�j\n\n";
            }

            void defense_result(const PlayerHero& to, const int power)
            {
                std::cout << "> " << to.get_name() << " �� " << power << " �̃V�[���h�𓾂��i�h��F" << to.get_shield() << "�j\n\n";
            }

            void defender_dead_message(const PlayerHero& hero)
            {
                std::cout << "> " << hero.get_name() << " �� �킢�̏�ɓ|�ꂽ...\n\n";
            }

            void round_exceed()
            {
                std::cout << "> " << "��������\n\n";
            }

            void show_experience_gain(int exp, int total_exp, int level, const char* name)
            {
                std::cout << "�y" << name << "�F�o���l�l���z\n";
                std::cout << "  + " << exp << " EXP ����ɓ��ꂽ�I\n";
                std::cout << "  �݌v EXP�F " << total_exp << "\n";
                std::cout << "  ���݂̃��x���FLv " << level << "\n";
            }

            void show_level_up(int new_level)
            {
                std::cout << "�y���x���A�b�v�I�z\n";
                std::cout << "  Lv " << new_level << " �ɓ��B�I\n";
            }

            void end_message()
            {
                std::cout << "�ΐ�I��\n";
                std::cout << "���j���[�ɖ߂�\n";
            }
        }

        namespace battle_tower
        {
            void title()
            {
                std::cout << "\n";
                std::cout << "==============================\n";
                std::cout << "      �o�g���^���[ ����J�n�I\n";
                std::cout << "==============================\n";
            }

            void next_level_title(int next_level)
            {
                std::cout << "> �� " << next_level << " �K�֐i��...\n";
            }

            void end_message(int final_level)
            {
                std::cout << "==============================\n";
                std::cout << "> ����I��\n";
                std::cout << "  �Ō�ɓ��B�����̂͑� " << final_level << " �w�������c\n";
                std::cout << "==============================\n";
            }

            void end_message_cleared(int final_level)
            {
                std::cout << "==============================\n";
                std::cout << "   �o�g���^���[���e�I�S " << final_level << " �w��˔j�I\n";
                std::cout << "   �N�̖��́A�`���ƂȂ邾�낤�I\n";
                std::cout << "==============================\n";
            }
        }
    }

    namespace message
    {
        void press_any_key_menu()
        {
            std::cout << "�����L�[�������ƃ��j���[�ɖ߂�܂��c\n";
        }

        void press_any_key_continue()
        {
            std::cout << "�����L�[�������Ƒ����c\n";
        }

        namespace input
        {
            void retry()
            {
                std::cout << "�����ȓ��͂ł��B������x���͂��Ă��������B\n\n";
            }
        }
    }

    namespace format_line
    {
        void blank()
        {
            std::cout << "\n";
        }

        void block()
        {
            std::cout << "\n������������������������������������������������������������\n";
        }

        void single_line()
        {
            std::cout << "\n------------------------------\n";
        }

        void double_line()
        {
            std::cout << "\n==============================\n";
        }
    }
}
