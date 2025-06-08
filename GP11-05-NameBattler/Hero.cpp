#include <cstdlib>
#include "cstring"
#include "Hero.h"
#include "utils.h"

Hero::Hero(const char* name)
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
    
    cards_ = new Card*[MAX_CARDS];
    cards_count_ = 0;
    
    generate_cards();
}

Hero::~Hero()
{
    for (int i = 0; i < cards_count_; i++)
    {
        delete cards_[i];
    }
    delete[] cards_;
}

const char* Hero::get_name() const
{
    return name_;
}

Ability Hero::get_ability() const
{
    return ability_;
}

Card** Hero::get_cards() const
{
    return cards_;
}

int Hero::get_cards_size() const
{
    return cards_count_;
}

int Hero::get_rate() const
{
    return ability_.attack + ability_.defense + ability_.speed + ability_.hp;
}

void Hero::generate_cards()
{
    srand(seed_);
    
    constexpr int num_cards = MAX_CARDS;
    
    for (int i = 0; i < num_cards && cards_count_ < MAX_CARDS; i++)
    {
        int card_type = rand() % 3;
        
        switch (card_type)
        {
            case ATTACK:
            {
                int power = (ability_.attack / 4) + (rand() % 20) + 5;
                cards_[cards_count_] = new AttackCard(power);
                cards_count_++;
                break;
            }
            case HEAL:
            {
                int power = (ability_.hp / 8) + (rand() % 15) + 3;
                cards_[cards_count_] = new HealCard(power);
                cards_count_++;
                break;
            }
            case DEFENSE:
            {
                int power = (ability_.defense / 6) + (rand() % 12) + 2;
                cards_[cards_count_] = new DefenseCard(power);
                cards_count_++;
                break;
            }
            default:
                break;
        }
    }
}