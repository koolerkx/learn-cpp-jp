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
            
            std::cout << " ���O �F " << character.get_name() << "\n";
            std::cout << "\n [ �\�͒l ]\n";
            std::cout << "  �̗́@�F " << ability.hp << "\n";
            std::cout << "  �U���@�F " << ability.attack << "\n";
            std::cout << "  �h��@�F " << ability.defense << "\n";
            std::cout << "  ���x�@�F " << ability.speed << "\n";
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
                std::cout << "        �l�[���o�g���[        \n";
                std::cout << "==============================\n";
                std::cout << "\n";
                std::cout << " 1. �L��������\n";
                std::cout << " 2. ��l�ŗV��\n";
                std::cout << " 3. AI�ΐ�\n";
                std::cout << " 9. �Q�[���I��\n";
                std::cout << "\n";
                std::cout << "==============================\n";
            }

            void option_message()
            {
                std::cout << "�I�����Ă��������i1/2/3/9�j: ";
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
                std::cout << "          �L��������          \n";
                std::cout << "------------------------------\n";
            }
            
            void profile_title()
            {
                std::cout << "==============================\n";
                std::cout << "        �L�����v���t�B�[��     \n";
                std::cout << "==============================\n";
            }

            void name_input_message()
            {
                std::cout << "�L�����̖��O���Ă�ł��������F";
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
                std::cout << "\n���ʁF�w" << name << "�x�������ɏ������ꂽ�I\n\n";
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
            std::cout << "������������������������������������������������������������\n\n";
        }
    }
}
