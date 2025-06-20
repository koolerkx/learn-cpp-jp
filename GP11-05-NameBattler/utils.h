/**
 * @file    utils.h
 * @brief   汎用ユーティリティ関数
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef UTILS_H
#define UTILS_H

#include <functional>

using uint = unsigned int;

/**
 * @namespace utils
 * @brief     入力検証とランダム数値生成
 */

namespace utils
{
    unsigned int hash_chars(const char* chars);
    int random(const int lower_limit, const int upper_limit);

    namespace input
    {
        void cleanup_input();
        
        int validated_input(
            const std::function<bool(int)>& validator,
            const std::function<void()>& input_message
        );

        namespace validator
        {
            std::function<bool(int)> is_in_range(int min, int max);
            std::function<bool(int)> is_in_list(const int* valid_values, int size);
        }
    }
}

#endif // UTILS_H