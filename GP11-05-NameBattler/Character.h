#pragma once
struct Ability
{
    int hp;
    int attack;
    int defense;
    int speed;
};

class Character
{
public:
    Character(char* name);
    int get_score() const;
    const char* get_name() const;
    Ability get_ability() const;
private:
    char name_[256];
    Ability ability_;

    Ability generate_ability(char* chars);
};
