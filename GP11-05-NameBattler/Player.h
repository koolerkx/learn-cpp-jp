#pragma once
#include "Hero.h"

constexpr int PLAYER_LABEL_NAME_MAX_LENGTH = 5;

class Player
{
public:
    Player(const char* label, const Hero* hero);

    const Hero* get_hero() const;
    char label[PLAYER_LABEL_NAME_MAX_LENGTH];
private:
    const Hero* hero_;
};
