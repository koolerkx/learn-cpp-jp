#include "PlayerHero.h"

#include <memory>
#include <vector>
#include <cstring>
#include <algorithm>

#include "Battle.h"

PlayerHero::PlayerHero(Player* player, const Hero* hero)
{
    player_ = player;
    hero_ = hero;

    hp_ = hero->get_ability().hp;
    
    initialize_cards();
}

void PlayerHero::initialize_cards()
{
    const std::vector<std::unique_ptr<Card>>& hero_cards = hero_->get_cards();
    available_cards_.reserve(hero_cards.size());
    
    for (const std::unique_ptr<Card>& card : hero_cards)
    {
        available_cards_.push_back(card.get());
    }
}

const std::vector<const Card*>& PlayerHero::get_available_cards() const
{
    return available_cards_;
}

const Card* PlayerHero::get_card(const int index) const
{
    if (index >= 0 && index < static_cast<int>(available_cards_.size()))
    {
        return available_cards_[index];
    }
    return nullptr;
}

void PlayerHero::take_damage(const int power)
{
    const int applied_damage = std::max(0, power - shield_);
    shield_ = std::max(0, shield_ - power);

    hp_ = std::max(0, hp_ - applied_damage);
}

void PlayerHero::take_heal(const int power)
{
    const int applied_heal = std::max(0, power);
    const int max_hp = get_max_hp();

    hp_ = std::min(max_hp, hp_ + applied_heal);
}

void PlayerHero::take_shield(const int power)
{
    constexpr int MAX_SHIELD = 256;
    const int applied_shield = shield_ + std::max(0, power);
    shield_ = std::min(applied_shield, MAX_SHIELD);
}