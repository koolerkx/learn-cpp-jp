#include "Card.h"
#include "Battle.h"

Card::Card(const char* label, const int power)
{
    label_ = label;
    power_ = power;
}

void AttackCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply)
{
    int damage = user.get_damage(multiply);
    target.take_damage(damage);
}

void HealCard::apply_card(PlayerHero&, PlayerHero& target, float multiply)
{
    int power = static_cast<int>(power_ * multiply);
    target.take_heal(power);
}


void DefenseCard::apply_card(PlayerHero&, PlayerHero& target, float multiply)
{
    int power = static_cast<int>(power_ * multiply);
    target.take_shield(power);
}
