#include <cstdlib>

namespace utils
{
    // DJB2 Hash Algorithm
    unsigned int hash_chars(const char* chars)
    {
        unsigned int hash = 5381;   // DJB2 initial value

        while (*chars)
        {
            hash = hash * 33 + static_cast<unsigned char>(*chars);
            chars++;
        }

        return hash;
    }
}
