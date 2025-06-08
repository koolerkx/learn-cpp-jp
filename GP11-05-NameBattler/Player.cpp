#include "Player.h"

#include <cstring>

Player::Player(const char* label, const Hero* hero)
{
    strncpy_s(
        this->label, PLAYER_LABEL_NAME_MAX_LENGTH,
        label, PLAYER_LABEL_NAME_MAX_LENGTH
    );

    hero_ = hero;
}

const Hero* Player::get_hero() const
{
    return hero_;
}
