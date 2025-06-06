#include "PlayerHero.h"

#include <memory>
#include <vector>

#include "Battle.h"

PlayerHero::PlayerHero(Player* player, Hero* hero)
{
    player_ = player;
    hero_ = hero;

    hp_ = hero->get_ability().hp;
}

Card* PlayerHero::get_available_cards()
{
    return available_cards_;
}

Card* PlayerHero::get_card(const int index)
{
    return &available_cards_[index];
}

int PlayerHero::get_damage(const float multiply) const
{
    return static_cast<int>(static_cast<float>(hero_->get_ability().attack) * multiply);
}

void PlayerHero::take_damage(const int power)
{
    int applied_damage = std::max(0, power - shield_);
    shield_ = std::max(0, shield_ - power);

    hp_ = hp_ - applied_damage;
}


void PlayerHero::take_heal(int power)
{
    int applied_heal = std::max(0, power);

    hp_ = hp_ + applied_heal;
}

void PlayerHero::take_shield(int power)
{
    shield_ = shield_ + std::max(0, power);
}