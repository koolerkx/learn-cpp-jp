#include "Card.h"
#include "Battle.h"
#include "view.h"

Card::Card(const char* label, const int power, const CARD_TYPE type)
{
    label_ = label;
    power_ = power;
    type_ = type;
}

float AttackCard::calculate_score(const PlayerHeroAI& ph) const
{
    float hp_percentage = static_cast<float>(ph.get_hp()) / static_cast<float>(ph.get_max_hp());
    float power = static_cast<float>(ph.get_attack()) / 4 + static_cast<float>(power_);
    
    return 100 * hp_percentage * power;
}

int AttackCard::apply_card(PlayerHero& user, PlayerHero& target, float multiply) const
{
    // based on multiply(0-2), attack bias from 100% to 200%
    float bias = 1.0f + multiply * 0.5f;
    int offset = static_cast<int>(static_cast<float>(user.get_attack()) * bias);
    
    int power = power_ + offset;
    target.take_damage(power);

    return power;
}

void AttackCard::result_message(PlayerHero&, PlayerHero& target, int power) const
{
    view::flow::battle::attack_result(target, power);
}


float HealCard::calculate_score(const PlayerHeroAI& ph) const
{
    float hp_percentage = static_cast<float>(ph.get_hp()) / static_cast<float>(ph.get_max_hp());
    float power = static_cast<float>(ph.get_max_hp()) / 4 + static_cast<float>(power_);
    
    return 100 * (1 - hp_percentage) * power;
}

int HealCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    // based on multiply(0-2), healing offset from HP 15% to 45% 
    float bias = 0.15f + multiply * 0.15f;
    int offset = static_cast<int>(static_cast<float>(user.get_max_hp()) * bias);
    
    int power = power_ + offset;
    user.take_heal(power);

    return power;
}

void HealCard::result_message(PlayerHero& user, PlayerHero&, int power) const
{
    view::flow::battle::heal_result(user, power);
}

float DefenseCard::calculate_score(const PlayerHeroAI& ph) const
{
    float hp_percentage = static_cast<float>(ph.get_hp()) / static_cast<float>(ph.get_max_hp());
    float power = static_cast<float>(ph.get_defense()) / 4 + static_cast<float>(power_);
    
    return 100 * (1 - hp_percentage) * power;
}

int DefenseCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    float bias = 0.1f + multiply * 0.2f;
    int offset = static_cast<int>(static_cast<float>(user.get_defense()) * bias);

    int power = power_ + offset;
    user.take_shield(power);

    return power;
}

void DefenseCard::result_message(PlayerHero& user, PlayerHero&, int power) const
{
    view::flow::battle::defense_result(user, power);
}
