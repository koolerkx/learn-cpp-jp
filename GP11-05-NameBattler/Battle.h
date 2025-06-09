#pragma once

#include "Player.h"
#include "PlayerHero.h"

class Battle
{
public:
    Battle(Player* p1, Player* p2);
    
    void start();
    
    static constexpr int DICE_LOWER = 0;
    static constexpr int DICE_UPPER = 10;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;
    static float offset_dice_multiplier(int dice_value);
private:
    std::vector<std::unique_ptr<PlayerHero>> hero_order_;

    static const Card* handle_card_select(const PlayerHero& ph);

    static float draw_dice();
    
    int current_order = 0;
};
