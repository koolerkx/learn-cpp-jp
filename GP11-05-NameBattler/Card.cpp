/**
 * @file    Card.cpp
 * @brief   �J�[�h�̊�{�N���X�Ɣh���N���X
 * @details �J�[�h�͉p�Y�ɐ������ꂽ�ŗL�X�L���ŁA�o�g���̎��g������
 * @author  KOOLER FAN
 * @date    2025-06-12
 * @note �݌v��p�Y���琶���������̂Ȃ̂ŁA�B�ꐫ��ۂ��߁A�J�[�h�̓R�s�[����֎~�ł�
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
 * @return �������e���̒l
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
 * @return �������e���̒l
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
 * @return �������e���̒l
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
