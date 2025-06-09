#include <cstdlib>
#include "cstring"
#include "Hero.h"
#include "utils.h"
#include <memory>

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
    
    cards_.reserve(MAX_CARDS);
    
    generate_cards();
}

const char* Hero::get_name() const
{
    return name_;
}

Ability Hero::get_ability() const
{
    return ability_;
}

const std::vector<std::unique_ptr<Card>>& Hero::get_cards() const
{
    return cards_;
}

int Hero::get_cards_size() const
{
    return static_cast<int>(cards_.size());
}

int Hero::get_rate() const
{
    return ability_.attack + ability_.defense + ability_.speed + ability_.hp;
}

void Hero::generate_cards()
{
    srand(seed_);
    
    constexpr int num_cards = MAX_CARDS;
    
    for (int i = 0; i < num_cards && cards_.size() < MAX_CARDS; i++)
    {
        CARD_TYPE card_type = static_cast<CARD_TYPE>(rand() % 3);
        
        switch (card_type)
        {
        case CARD_TYPE::ATTACK:
            {
                int power = (ability_.attack / 4) + (rand() % 20) + 5;
                cards_.emplace_back(std::make_unique<AttackCard>(power));
                break;
            }
        case CARD_TYPE::HEAL:
            {
                int power = (ability_.hp / 8) + (rand() % 15) + 3;
                cards_.emplace_back(std::make_unique<HealCard>(power));
                break;
            }
        case CARD_TYPE::DEFENSE:
            {
                int power = (ability_.defense / 6) + (rand() % 12) + 2;
                cards_.emplace_back(std::make_unique<DefenseCard>(power));
                break;
            }
        }
    }
}