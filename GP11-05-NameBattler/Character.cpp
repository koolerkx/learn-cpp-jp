#include "Character.h"
#include "cstring"

Character::Character(char* name)
{
    strncpy_s(name_, name, sizeof(name_));
    ability_ = generate_ability(name);
}

const char* Character::get_name() const
{
    return name_;
}

Ability Character::get_ability() const
{
    return ability_;
}


Ability Character::generate_ability(char* chars)
{
    int seed = (int)(char)chars[0];
    
    return {
        1,
        2,
        3,
        4,
    };
}

int Character::get_score() const
{
    return ability_.attack + ability_.defense + ability_.speed + ability_.defense;
}