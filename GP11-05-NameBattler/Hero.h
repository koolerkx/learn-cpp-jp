#pragma once

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
    Hero(char* name);

    int get_rate() const;
    const char* get_name() const;
    Ability get_ability() const;

    static constexpr int NAME_MAX_LENGTH = 256;
    static constexpr int ABILITY_MAX_VALUE = 256;
private:
    char name_[NAME_MAX_LENGTH];
    unsigned int seed_;
    
    Ability ability_;
};
