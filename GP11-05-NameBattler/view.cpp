#include <iostream>
#include "view.h"

#include "Hero.h"

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
            std::cout << "  ���x�@�F " << ability.speed << "\n";
            std::cout << "==============================\n";
        }

        void show_list(const Hero* heroes, int count)
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << i + 1 << ": " << heroes[i].get_name() << " (" << heroes[i].get_rate() << ")\n";
            }
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
    }

    namespace message
    {
        void press_any_key()
        {
            std::cout << "�����L�[�������ƃ��j���[�ɖ߂�܂��c\n";
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
    }
}
