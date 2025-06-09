#pragma once
#include "Hero.h"

constexpr int PLAYER_LABEL_NAME_MAX_LENGTH = 5;

class Player
{
public:
    Player(const char* player_label, const Hero* hero);
    virtual ~Player() = default;
    
    const Hero* get_hero() const;
    char label[PLAYER_LABEL_NAME_MAX_LENGTH];

    virtual bool is_ai() const { return false; }

private:
    const Hero* hero_;
};

class PlayerAI : public Player
{
public:
    PlayerAI(const char* player_label, const Hero* hero) : Player(player_label, hero)
    {
    }

    bool is_ai() const override { return true; }
};
