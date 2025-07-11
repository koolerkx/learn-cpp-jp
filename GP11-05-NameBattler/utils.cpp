/**
 * @file    utils.cpp
 * @brief   汎用ユーティリティ関数
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#include "utils.h"

#include <iostream>
#include "view.h"

namespace utils
{
    /**
     * @brief ハッシュを用いて、文字列から数字を変換する
     * @details DJB2ハッシュアルゴリズム
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
     * @brief ランダム数値
     * @param lower_limit 以上
     * @param upper_limit 以下
     * @note シード(`srand()`)は外で決めるべき
     */
    int random(const int lower_limit, const int upper_limit)
    {
        return rand() % (upper_limit - lower_limit + 1) + lower_limit;
    }

    /**
     * @namespace input
     * @brief 入力関連処理
     */
    namespace input
    {
        void cleanup_input()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        /**
         * @brief 入力の有効性判断、有効まで入力が続く
         * @param validator 有効性を判断する関数
         * @param input_message 入力のメッセージ
         * @return プレイヤーが入力した有効の値
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
         * @brief 有効性を判断する関数
         * @note 戻り値は関数の形ですべき
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
