#pragma once
#include <cstdint>

class PlayerHero;
class PlayerHeroAI;

enum class CARD_TYPE : std::uint8_t
{
    ATTACK = 0,
    HEAL = 1,
    DEFENSE = 2
};

class Card
{
public:
    Card(const char* label, const int power, const CARD_TYPE type);

    virtual ~Card() = default;
    // prevent getting shallow copy
    Card(const Card&) = delete;
    Card& operator=(const Card&) = delete;
    Card(Card&&) = delete;
    Card& operator=(Card&&) = delete;

    const char* get_label() const { return label_; }
    virtual int get_power() const { return power_; }

    virtual float calculate_score(const PlayerHeroAI& ph) const = 0;
    CARD_TYPE get_type() const { return type_; }

    virtual int apply_card(PlayerHero& user, PlayerHero& target, float multiply) const = 0;
    virtual void result_message(PlayerHero& user, PlayerHero& target, int power) const = 0;

protected:
    int power_;
    const char* label_;
    CARD_TYPE type_;
};

constexpr const char* ATTACK_CARD_LABEL = "Å£ çUåÇçsìÆ";
class AttackCard : public Card
{
public:
    AttackCard(int power)
        : Card(ATTACK_CARD_LABEL, power, CARD_TYPE::ATTACK) {}

    float calculate_score(const PlayerHeroAI& ph) const override;
    int apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
    void result_message(PlayerHero& user, PlayerHero& target, int power) const override;
};

constexpr const char* HEAL_CARD_LABEL = "Åú é°ñ¸çsìÆ";
class HealCard : public Card
{
public:
    HealCard(int power)
        : Card(HEAL_CARD_LABEL, power, CARD_TYPE::HEAL) {}

    float calculate_score(const PlayerHeroAI& ph) const override;
    int apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
    void result_message(PlayerHero& user, PlayerHero& target, int power) const override;
};

constexpr const char* DEFENSE_CARD_LABEL = "Å° ñhå‰çsìÆ";
class DefenseCard : public Card
{
public:
    DefenseCard(int power)
        : Card(DEFENSE_CARD_LABEL, power, CARD_TYPE::DEFENSE) {}

    float calculate_score(const PlayerHeroAI& ph) const override;
    int apply_card(PlayerHero& user, PlayerHero& target, float multiply) const override;
    void result_message(PlayerHero& user, PlayerHero& target, int power) const override;
};