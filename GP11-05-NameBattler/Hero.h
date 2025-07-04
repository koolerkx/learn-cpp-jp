/**
 * @file    Hero.h
 * @brief   英雄キャラクターの管理
 * @author  KOOLER FAN
 * @date    2025-06-12
 * @note 英雄は経験値以外、生成されたもの故に、変更すべきではない、唯一性を保つ為、コピー操作は禁止です
 */

#ifndef HERO_H
#define HERO_H

#include "Card.h"
#include <vector>
#include <memory>

struct Ability
{
    int hp;
    int attack;
    int defense;
};

/**
 * @class   Hero
 * @brief   プレイヤーが持っているキャラクターのデータ構造
 */
class Hero
{
public:
    Hero(const char* name);
    ~Hero() = default;

    // only allow to move to prevent memory leak
    Hero(const Hero&) = delete;
    Hero& operator=(const Hero&) = delete;
    Hero(Hero&&) noexcept = default;
    Hero& operator=(Hero&&) noexcept = default;

    int get_rate() const;
    const char* get_name() const;
    Ability get_ability() const;
    Ability get_scaled_ability() const;

    const std::vector<std::unique_ptr<Card>>& get_cards() const;
    int get_cards_size() const;

    int get_experience() const;
    void gain_experience(int exp);
    
    static constexpr int NAME_MAX_LENGTH = 256;
    static constexpr int ABILITY_MAX_VALUE = 256;
    static constexpr int MAX_CARDS = 5;

private:
    char name_[NAME_MAX_LENGTH];
    unsigned int seed_;
    std::vector<std::unique_ptr<Card>> cards_;
    
    Ability ability_;

    int experience_ = 0;
    
    void generate_cards();
};

/**
 * @namespace   hero_level
 * @brief       レベルに関係ある数学の式がまとまった所
 */
namespace hero_level
{
    // レベルアップ曲線の定数
    // 二次曲線：レベル＝高さ×（レベルの2乗-1）
    constexpr int base = 50;
    constexpr float slope = 2.0f;

    // レベルの定数
    constexpr int MAX_LEVEL = 10;
    constexpr float LEVEL_SCALE_MIN = 0.5f;
    constexpr float LEVEL_SCALE_MAX = 1.0f;
    
    int get_level(int exp);
    int get_expected_experience_for_battle(int level);
    float get_ability_scaler(int level);
}

#endif // HERO_H