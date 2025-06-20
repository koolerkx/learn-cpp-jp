/**
 * @file    Battle.h
 * @brief   バトルシステムの実装
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <functional>

#include "PlayerHero.h"

constexpr int BATTLE_HEROES = 2;

/**
 * @class    Battle
 * @brief   バトルシステム
 */
class Battle
{
public:
    Battle(PlayerHero* p1, PlayerHero* p2);

    bool run(); // return is_win

    static constexpr int MAX_ROUND = 20;

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

/**
 * @namespace dice
 * @brief   バトルシステムに使われるサイコロの実装
 */
namespace dice
{
    enum class YAKU: uint8_t
    {
        PINZORO, // 3x, ピンゾロ 0.46%
        ARASHI, // 2x, ぞろ目 2.31%
        SHIGORO, // 1.5x, シゴロ 2.78%
        TUJYOU, // 1x, 通常役 41.67%
        HIFUMI, // 0x, ヒフミ 2.78%
        OTHER // 0.8x, 役なし 52.78%
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

    YakuSet yaku_sets[];

    struct DiceYakuResult
    {
        YAKU yaku;
        float multiplier;
    };

    static DiceResult draw_dice();
    static DiceYakuResult dice_multiply(DiceResult& dice_state);

    static constexpr int DICE_LOWER = 1;
    static constexpr int DICE_UPPER = 6;
    static constexpr int DICE_BASE = (DICE_LOWER + DICE_UPPER) / 2;
};

#endif // BATTLE_H
