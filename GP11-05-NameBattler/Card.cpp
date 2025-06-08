#include "Card.h"
#include "Battle.h"

Card::Card(const char* label, const int power)
{
    label_ = label;
    power_ = power;
}

void AttackCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply) const
{
    // based on multiply(0-2), attack bias from 100% to 200%
    float bias = 1.0f + multiply * 0.5f;
    int offset = static_cast<int>(static_cast<float>(user.get_attack()) * bias);
    
    int power = power_ + offset;
    target.take_damage(power);
}

void HealCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    // based on multiply(0-2), healing offset from HP 15% to 45% 
    float bias = 0.15f + multiply * 0.15f;
    int offset = static_cast<int>(static_cast<float>(user.get_max_hp()) * bias);
    
    int power = power_ + offset;
    user.take_heal(power);
}

void DefenseCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    float bias = 0.1f + multiply * 0.2f;
    int offset = static_cast<int>(static_cast<float>(user.get_defense()) * bias);

    int power = power_ + offset;
    user.take_shield(power);
}
