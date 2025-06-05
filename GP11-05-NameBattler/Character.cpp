#include <cstdlib>
#include "cstring"
#include "Character.h"
#include "utils.h"

Character::Character(char* name)
{
    strncpy_s(name_, name, sizeof(name_));
    
    seed_ = utils::hash_chars(name_);

    srand(seed_);
    
    ability_ = {
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
    };
}

const char* Character::get_name() const
{
    return name_;
}

Ability Character::get_ability() const
{
    return ability_;
}

int Character::get_rate() const
{
    return ability_.attack + ability_.defense + ability_.speed + ability_.hp;
}