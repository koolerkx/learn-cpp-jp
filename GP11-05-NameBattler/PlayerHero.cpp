#include "PlayerHero.h"

#include <memory>
#include <vector>
#include <cstring>

#include "Battle.h"

PlayerHero::PlayerHero(Player* player, Hero* hero)
{
    player_ = player;
    hero_ = hero;

    hp_ = hero->get_ability().hp;
    
    initialize_cards();
}

PlayerHero::~PlayerHero()
{
    // it is shallow copy from hero
    delete[] available_cards_;
    available_cards_ = nullptr;
}

PlayerHero::PlayerHero(const PlayerHero& other)
{
    player_ = other.player_;
    hero_ = other.hero_;
    hp_ = other.hp_;
    shield_ = other.shield_;
    available_cards_size = other.available_cards_size;
    
    available_cards_ = new Card*[available_cards_size];
    for (int i = 0; i < available_cards_size; i++)
    {
        available_cards_[i] = other.available_cards_[i];
    }
}


void PlayerHero::initialize_cards()
{
    Card** hero_cards = hero_->get_cards();
    available_cards_size = hero_->get_cards_size();
    
    available_cards_ = new Card*[available_cards_size];

    // shallow copy
    for (int i = 0; i < available_cards_size; i++)
    {
        available_cards_[i] = hero_cards[i];
    }
}

Card* const* PlayerHero::get_available_cards() const
{
    return available_cards_;
}

const Card* PlayerHero::get_card(const int index) const
{
    if (index >= 0 && index < available_cards_size)
    {
        return available_cards_[index];
    }
    return nullptr;
}

void PlayerHero::take_damage(const int power)
{
    const int applied_damage = std::max(0, power - shield_);
    shield_ = std::max(0, shield_ - power);

    hp_ = hp_ - applied_damage;
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