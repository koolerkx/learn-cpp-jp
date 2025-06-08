#pragma once

#include "Player.h"
#include "PlayerHero.h"

class Battle
{
public:
    Battle(Player* p1, Player* p2);
    ~Battle();
    
    void start();
    
    Player* p1;
    Player* p2;
    
    static constexpr int DICE_LOWER = 0;
    static constexpr int DICE_UPPER = 10;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;
    static float offset_dice_multiplier(int dice_value);
private:
    PlayerHero** hero_order;
    
    int hero_order_size;
    int current_order = 0;
};
