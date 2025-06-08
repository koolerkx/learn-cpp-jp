#pragma once
#include "Card.h"
#include "Player.h"
#include "Hero.h"

class PlayerHero
{
public:
    PlayerHero(Player* player, const Hero* hero);
    ~PlayerHero();
    
    PlayerHero(const PlayerHero& other);
    
    const char* get_player_label() const { return player_->label; }
    
    const char* get_name() const { return hero_->get_name(); }
    int get_hp() const { return hp_; }
    int get_max_hp() const { return hero_->get_ability().hp; }

    Card* const* get_available_cards() const;
    int get_available_cards_size() const { return available_cards_size; } 
    const Card* get_card(const int index) const;

    int get_attack() const { return  (hero_->get_ability().attack); }
    int get_defense() const { return (hero_->get_ability().defense); }
    
    void take_damage(int power);
    void take_heal(int power);
    void take_shield(int power);
    
private:
    Player* player_;
    const Hero* hero_;
    
    Card** available_cards_;
    int available_cards_size;
    
    int hp_;
    int shield_ = 0;
    
    void initialize_cards();
};