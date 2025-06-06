#pragma once
#include "Hero.h"

constexpr int PLAYER_LABEL_NAME_MAX_LENGTH = 5;

class Player
{
public:
    Player(const char* label, Hero* hero);

    Hero* get_hero();
    char label[PLAYER_LABEL_NAME_MAX_LENGTH];
private:
    Hero* hero_;
};
