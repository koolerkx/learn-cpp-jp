#pragma once

#include <functional>

#include "PlayerHero.h"

constexpr int BATTLE_HEROES = 2;

class Battle
{
public:
    Battle(PlayerHero* p1, PlayerHero* p2);

    bool run(); // return is_win

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

    static float offset_dice_multiplier(int dice_value);

    int attacker_index() const { return (round_) % BATTLE_HEROES; }
    int defender_index() const { return (round_ + 1) % BATTLE_HEROES; }
};

namespace dice
{
    enum class YAKU: uint8_t
    {
        PINZORO, // 2x, �s���]�� 0.46%
        ARASHI, // 1.4x, ����� 2.31%
        SHIGORO, // 1.1x, �V�S�� 2.78%
        TUJYOU, // 1x, �ʏ�� 41.67%
        HIFUMI, // 0x, �q�t�~ 2.78%
        OTHER // 0x, ���Ȃ� 52.78%
    };

    struct DiceResult
    {
        int dice_1;
        int dice_2;
        int dice_3;
    };

    struct YakuSet
    {
        YAKU yaku;
        float multiplier;
        std::function<bool(DiceResult)> test;
    };

    extern YakuSet yaku_sets[];
    extern const int yaku_sets_count;
    
    struct DiceYakuResult
    {
        YAKU yaku;
        float multiplier;
    };

    static DiceResult draw_dice();
    static DiceYakuResult dice_multiply(DiceResult dice_state);

    static constexpr int DICE_LOWER = 1;
    static constexpr int DICE_UPPER = 6;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;
};
