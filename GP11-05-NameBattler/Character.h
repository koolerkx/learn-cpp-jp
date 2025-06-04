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

    void show_profile() const;
    
    static constexpr int NAME_MAX_LENGTH = 256;  
private:
    char name_[NAME_MAX_LENGTH];
    Ability ability_;

    Ability generate_ability(char* chars);
};
