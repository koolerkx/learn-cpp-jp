#pragma once
#include "Card.h"
#include "Player.h"
#include "Hero.h"
#include <vector>

class PlayerHero
{
public:
    PlayerHero(Player* player, const Hero* hero);

    // prevent memory leak
    PlayerHero(const PlayerHero&) = delete;
    PlayerHero& operator=(const PlayerHero&) = delete;
    PlayerHero(PlayerHero&&) noexcept = default;
    PlayerHero& operator=(PlayerHero&&) noexcept = default;
    
    const char* get_player_label() const { return player_->label; }
    
    const char* get_name() const { return hero_->get_name(); }
    int get_hp() const { return hp_; }
    int get_max_hp() const { return hero_->get_ability().hp; }
    int get_shield() const { return shield_; }

    const std::vector<const Card*>& get_available_cards() const;
    const Card* get_card(const int index) const;

    int get_attack() const { return  (hero_->get_ability().attack); }
    int get_defense() const { return (hero_->get_ability().defense); }
    
    void take_damage(int power);
    void take_heal(int power);
    void take_shield(int power);

    constexpr static int MAX_SHIELD = 256;
    
private:
    Player* player_;
    const Hero* hero_;
    
    std::vector<const Card*> available_cards_;
    
    int hp_;
    int shield_ = 0;
    
    void initialize_cards();
};