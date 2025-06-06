#include "Player.h"

#include <cstring>

Player::Player(const char* label, Hero* hero)
{
    strncpy_s(
        this->label, PLAYER_LABEL_NAME_MAX_LENGTH,
        label, PLAYER_LABEL_NAME_MAX_LENGTH
    );

    hero_ = hero;
}

Hero* Player::get_hero()
{
    return hero_;
}
