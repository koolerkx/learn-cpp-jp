/**
 * @file    utils.cpp
 * @brief   �ėp���[�e�B���e�B�֐�
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#include "utils.h"

#include <iostream>
#include "view.h"

namespace utils
{
    /**
     * @brief �n�b�V����p���āA�����񂩂琔����ϊ�����
     * @details DJB2�n�b�V���A���S���Y��
     * @see https://qiita.com/yuu_7_ns/items/cbdc185c179f3e418eb5
     */
    unsigned int hash_chars(const char* chars)
    {
        unsigned int hash = 5381; // DJB2 initial value

        while (*chars)
        {
            hash = hash * 33 + static_cast<unsigned char>(*chars);
            chars++;
        }

        return hash;
    }

    /**
     * @brief �����_�����l
     * @param lower_limit �ȏ�
     * @param upper_limit �ȉ�
     * @note �V�[�h(`srand()`)�͊O�Ō��߂�ׂ�
     */
    int random(const int lower_limit, const int upper_limit)
    {
        return rand() % (upper_limit - lower_limit + 1) + lower_limit;
    }

    /**
     * @namespace input
     * @brief ���͊֘A����
     */
    namespace input
    {
        void cleanup_input()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        /**
         * @brief ���̗͂L�������f�A�L���܂œ��͂�����
         * @param validator �L�����𔻒f����֐�
         * @param input_message ���͂̃��b�Z�[�W
         * @return �v���C���[�����͂����L���̒l
         */
        int validated_input(
            const std::function<bool(int)>& validator,
            const std::function<void()>& input_message
        )
        {
            while (true)
            {
                int input;
                input_message();
                std::cin >> input;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    view::message::input::retry();
                    continue;
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (validator(input))
                {
                    return input;
                }
                view::message::input::retry();
            }
        }

        /**
         * @namespace validator
         * @brief �L�����𔻒f����֐�
         * @note �߂�l�͊֐��̌`�ł��ׂ�
         */
        namespace validator
        {
            std::function<bool(int)> is_in_range(int min, int max)
            {
                return [min, max](const int value) { return value >= min && value <= max; };
            }

            std::function<bool(int)> is_in_list(const int* valid_values, int size)
            {
                return [valid_values, size](const int value)
                {
                    for (int i = 0; i < size; i++)
                    {
                        if (valid_values[i] == value)
                        {
                            return true;
                        }
                    }
                    return false;
                };
            }
        }
    }
}
