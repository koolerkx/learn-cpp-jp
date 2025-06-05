#pragma once
#include <functional>
#include <iostream>

#include "view.h"

using uint = unsigned int;

namespace utils
{
    inline unsigned int hash_chars(const char* chars)
    {
        unsigned int hash = 5381; // DJB2 initial value

        while (*chars)
        {
            hash = hash * 33 + static_cast<unsigned char>(*chars);
            chars++;
        }

        return hash;
    }

    namespace input
    {
        inline void cleanup_input()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        inline int validated_input(
            const std::function<bool(int)>& validator,
            const std::function<void()>& input_message
        )
        {
            while (true)
            {
                int input;
                input_message();
                std::cin >> input;

                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    view::message::input::retry();
                    continue;
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if(validator(input))
                {
                    return input;
                }
                view::message::input::retry();
            }
        }

        namespace validator
        {
            inline std::function<bool(int)> is_in_range(int min, int max)
            {
                return [min, max](const int value) { return value >= min && value <= max; };
            }

            inline std::function<bool(int)> is_in_list(const int* valid_values, int size)
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
