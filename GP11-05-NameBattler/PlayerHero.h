#pragma once
#include "Card.h"
#include "Player.h"
#include "Hero.h"

class PlayerHero
{
public:
    PlayerHero(Player* player, Hero* hero);
    
    const char* get_player_label() const { return player_->label; }
    
    const char* get_name() const { return hero_->get_name(); }
    int get_hp() const { return hp_; }
    int get_max_hp() const { return hero_->get_ability().hp; }

    void set_hp(const int hp) { hp_ = hp; }

    Card* get_available_cards();
    int available_cards_size = -1;
    Card* get_card(const int index);

    int get_damage(float multiply) const;
    
    void take_damage(int power);
    void take_heal(int power);
    void take_shield(int power);
    
private:
    Player* player_;
    Hero* hero_;
    Card* available_cards_;
    
    int hp_;
    int shield_ = 0;
};

