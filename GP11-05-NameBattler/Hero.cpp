#include <cstdlib>
#include "cstring"
#include "Hero.h"
#include "utils.h"

Hero::Hero(char* name)
{
    strncpy_s(name_, name, Hero::NAME_MAX_LENGTH);

    seed_ = utils::hash_chars(name_);

    srand(seed_);

    ability_ = {
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
    };
    
}

const char* Hero::get_name() const
{
    return name_;
}

Ability Hero::get_ability() const
{
    return ability_;
}

Card* Hero::get_cards() const
{
}

int Hero::get_rate() const
{
    return ability_.attack + ability_.defense + ability_.speed + ability_.hp;
}
