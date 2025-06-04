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
            std::cout << "�I�����Ă��������i1/2/3/9�j: ";
        }
        void hint_back_to_menu()
        {
            std::cout << "�����L�[�������ƃ��j���[�ɖ߂�܂��c\n";
        }
        
        void show_summon_title()
        {
            std::cout << "------------------------------\n";
            std::cout << "          �L��������          \n";
            std::cout << "------------------------------\n";
        }
        void show_summon_profile_title()
        {
            std::cout << "==============================\n";
            std::cout << "        �L�����v���t�B�[��     \n";
            std::cout << "==============================\n";
        }
    }
}
