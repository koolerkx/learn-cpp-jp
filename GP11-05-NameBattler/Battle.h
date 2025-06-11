#pragma once

#include "PlayerHero.h"

constexpr int BATTLE_HEROES = 2;

class Battle
{
public:
    Battle(PlayerHero* p1, PlayerHero* p2);
    
    bool run(); // return is_win

    static constexpr int DICE_LOWER = 1;
    static constexpr int DICE_UPPER = 6;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;

private:
    int round_ = 1;

    PlayerHero* heroes_[BATTLE_HEROES];

    void start();
    bool update();
    void end();

    void advance_round();
    void execute_round();
    bool is_continue_round();
    
    static const Card* handle_card_select(const PlayerHero& ph);

    static float draw_dice();
    
    static float offset_dice_multiplier(int dice_value);
    
    int attacker_index() const { return (round_) % BATTLE_HEROES; }
    int defender_index() const { return (round_ + 1) % BATTLE_HEROES; }
};
