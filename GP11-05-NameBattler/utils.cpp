#include "utils.h"

#include <iostream>
#include "view.h"

namespace utils
{
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

    int random(const int lower_limit, const int upper_limit)
    {
        srand(static_cast<unsigned>(time(nullptr)));

        return rand() % (upper_limit - lower_limit + 1) + lower_limit;
    }

    namespace input
    {
        void cleanup_input()
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

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
