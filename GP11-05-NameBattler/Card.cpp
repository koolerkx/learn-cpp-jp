/**
 * @file    Card.cpp
 * @brief   カードの基本クラスと派生クラス
 * @details カードは英雄に生成された固有スキルで、バトルの時使うもの
 * @author  KOOLER FAN
 * @date    2025-06-12
 * @note 設計上英雄から生成したものなので、唯一性を保つため、カードはコピー操作禁止です
 */

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

/**
 * @return 効いた影響の値
 */
int AttackCard::apply_card(PlayerHero&, PlayerHero& target, float multiply) const
{
    int power = static_cast<int>(static_cast<float>(power_) * multiply);
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

/**
 * @return 効いた影響の値
 */
int HealCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    int power = static_cast<int>(static_cast<float>(power_) * multiply);
    user.take_heal(power);

    return power;
}

void HealCard::result_message(PlayerHero& user, PlayerHero&, int power) const
{
    view::flow::battle::heal_result(user, power);
}

float DefenseCard::calculate_score(const PlayerHeroAI& ph) const
{
    float hp_shield_percentage = static_cast<float>(ph.get_hp() + ph.get_shield()) / static_cast<float>(ph.get_max_hp());
    float power = static_cast<float>(ph.get_defense()) / 4 + static_cast<float>(power_);
    
    return 100 * (1 - hp_shield_percentage) * power;
}

/**
 * @return 効いた影響の値
 */
int DefenseCard::apply_card(PlayerHero& user, PlayerHero&, float multiply) const
{
    int power = static_cast<int>(static_cast<float>(power_) * multiply);
    user.take_shield(power);

    return power;
}

void DefenseCard::result_message(PlayerHero& user, PlayerHero&, int power) const
{
    view::flow::battle::defense_result(user, power);
}
