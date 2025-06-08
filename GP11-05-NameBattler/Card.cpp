#include "Card.h"
#include "Battle.h"

Card::Card(const char* label, const int power)
{
    label_ = label;
    power_ = power;
}

void AttackCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply) const
{
    // FIXME the damage
    int damage = power_ * user.get_damage(multiply);
    target.take_damage(damage);
}

void HealCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply) const
{
    int power = static_cast<int>(static_cast<float>(power_) * multiply);
    user.take_heal(power);
}

void DefenseCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply) const
{
    int power = static_cast<int>(static_cast<float>(power_) * multiply);
    user.take_shield(power);
}
