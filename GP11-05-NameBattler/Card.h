#pragma once
#include <cstdint>

class PlayerHero;

class Card
{
public:
    Card(const char* label, const int power);

    virtual ~Card() = default;
    // prevent getting shallow copy
    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;
    Card(Card&&) = delete;
    Card& operator=(Card&&) = delete;

    const char* get_label() const { return label_; }
    int get_power() const { return power_; }

    virtual void apply_card(PlayerHero& user, PlayerHero& target, float multiply) const = 0;
    
protected:
    int power_;
    const char* label_;
};

enum CARD_TYPE : std::uint8_t {
    ATTACK = 0,
    HEAL = 1,
    DEFENSE = 2
};

constexpr const char* ATTACK_CARD_LABEL = "çUåÇçsìÆ";

class AttackCard : public Card
{
public:
    AttackCard(const int power): Card(ATTACK_CARD_LABEL, power)
    {
    }

    void apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
};

constexpr const char* HEAL_CARD_LABEL = "é°ñ¸çsìÆ";

class HealCard : public Card
{
public:
    HealCard(const int power): Card(HEAL_CARD_LABEL, power)
    {
    }

    void apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
};

constexpr const char* DEFENSE_CARD_LABEL = "ñhå‰çsìÆ";

class DefenseCard : public Card
{
public:
    DefenseCard(const int power): Card(DEFENSE_CARD_LABEL, power)
    {
    }

    void apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
};
