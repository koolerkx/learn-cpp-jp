#pragma once
#include "Card.h"

struct Ability
{
    int hp;
    int attack;
    int defense;
    int speed;
};

class Hero
{
public:
    Hero(const char* name);
    ~Hero();

    int get_rate() const;
    const char* get_name() const;
    Ability get_ability() const;

    Card** get_cards() const;
    int get_cards_size() const;

    static constexpr int NAME_MAX_LENGTH = 256;
    static constexpr int ABILITY_MAX_VALUE = 256;
    static constexpr int MAX_CARDS = 5;

private:
    char name_[NAME_MAX_LENGTH];
    unsigned int seed_;
    Card** cards_;
    int cards_count_;
    
    Ability ability_;
    
    void generate_cards();
};