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

            std::cout << " ���O �F " << hero.get_name() << "\n";
            std::cout << "\n [ �\�͒l ]\n";
            std::cout << "  �̗́@�F " << ability.hp << "\n";
            std::cout << "  �U���@�F " << ability.attack << "\n";
            std::cout << "  �h��@�F " << ability.defense << "\n";
            std::cout << "  ���x�@�F " << ability.speed << "\n\n";

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
                std::cout << " 2. ��l�ŗV��\n";
                std::cout << " 3. AI�ΐ�\n";
                std::cout << " 4. �p�Y�Ǘ�\n";
                std::cout << " 9. �Q�[���I��\n";
                std::cout << "\n";
                std::cout << "==============================\n";
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
                std::cout << "\n------------------------------\n";
                std::cout << "             �p�Y����          \n";
                std::cout << "------------------------------\n";
            }

            void profile_title()
            {
                std::cout << "\n==============================\n";
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
                std::cout << "\n���ʁF�w" << name << "�x�������ɏ������ꂽ�I\n";
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
                std::cout << "\n==============================\n";
                std::cout << "       �����p�Y�Ǘ����j���[\n";
                std::cout << "==============================\n\n";
                std::cout << " 1. �ꗗ�i���O�ƕ]���j\n";
                std::cout << " 2. �ڍׂ�����\n";
                std::cout << " 3. �p�Y���폜\n";
                std::cout << " 9. ���C�����j���[�ɖ߂�\n\n";
                std::cout << "==============================\n";
            }

            void hero_menu_option_message()
            {
                std::cout << "�I�����Ă��������i1/2/3/9�j: ";
            }

            void hero_list_title()
            {
                std::cout << "\n------------------------------\n";
                std::cout << "          �����p�Y�ꗗ          \n";
                std::cout << "------------------------------\n";
            }

            void hero_detail_title()
            {
                std::cout << "\n==============================\n";
                std::cout << "         �p�Y�̏ڍ׏��         \n";
                std::cout << "==============================\n";
            }

            void hero_detail_option_message()
            {
                std::cout << "�ڍׂ��������p�Y�̔ԍ�����͂��Ă��������F";
            }

            void hero_delete_title()
            {
                std::cout << "\n------------------------------\n";
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
            void player_select_hero(const char* label)
            {
                std::cout << "\n" << label << "�̑I��\n";
            }

            void select_hero_options()
            {
                std::cout << "�p�Y�̔ԍ�����͂��Ă��������F";
            }

            void battle_title()
            {
                std::cout << "------------------------------" << "\n";
                std::cout << "         �o�g���J�n�I" << "\n";
                std::cout << "------------------------------" << "\n\n";
            }

            void battle_round(const int round)
            {
                std::cout << "�y���E���h " << round << "�z";
            }

            void battle_round_hero_list(const std::vector<std::unique_ptr<PlayerHero>>& heroes, const int size)
            {
                std::cout << "�s�����F\n";
                for (int i = 0; i < size; i++)
                {
                    std::cout << i + 1 << " : (" << heroes[i]->get_player_label() << ") ";
                    std::cout << heroes[i]->get_name();
                    std::cout << " (HP: " << heroes[i]->get_hp() << "/" << heroes[i]->get_max_hp() << ", �h��l: " <<
                        heroes[i]->get_shield() << ")\n";
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

            void battle_round_attack_option_list(const std::vector<const Card*>& cards)
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

            void dice_result(const int dice)
            {
                std::cout << "> " << " �T�C�R������ (1d" << Battle::DICE_UPPER << ")�F" << dice << "\n";
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

            void end_message()
            {
                std::cout << "�ΐ�I��\n";
                std::cout << "���j���[�ɖ߂�\n";
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
        void show_block_separator()
        {
            std::cout << "\n������������������������������������������������������������\n";
        }

        void show_double_line()
        {
            std::cout << "\n==============================\n";
        }
    }
}
