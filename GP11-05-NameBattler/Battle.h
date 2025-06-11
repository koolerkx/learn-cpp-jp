#pragma once

#include "PlayerHero.h"

class Battle
{
public:
    Battle(std::unique_ptr<PlayerHero> p1, std::unique_ptr<PlayerHero> p2);
    
    void run();

    void advanced_round();
    void execute_round();
    bool is_continue_round();

    static constexpr int DICE_LOWER = 1;
    static constexpr int DICE_UPPER = 6;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;
    static float offset_dice_multiplier(int dice_value);

private:
    int round_ = 1;
    int current_hero = 0;

    std::vector<std::unique_ptr<PlayerHero>> heroes_;

    void start();
    bool update();
    void end();
    
    static const Card* handle_card_select(const PlayerHero& ph);

    static float draw_dice();

    int attacker_index() const { return (round_) % heroes_.size(); }
    int defender_index() const { return (round_ + 1) % heroes_.size(); }
};
