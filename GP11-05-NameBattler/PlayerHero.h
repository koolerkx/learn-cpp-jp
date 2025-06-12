/**
 * @file    PlayerHero.h
 * @brief   プレイヤーとCOMの英雄制御
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef PlayerHero_H
#define PlayerHero_H

#include "Card.h"
#include "Hero.h"
#include <vector>

constexpr int PLAYER_LABEL_NAME_MAX_LENGTH = 5;

enum class PLAYER_HERO_TYPE: uint8_t
{
    PLAYER = 0,
    COM = 1
};

/**
 * @class   PlayerHero
 * @brief   バトル用の一時的な英雄ラッパー
 * 固有ステータス（経験値）以外の数値はPlayerHeroで処理する
 * 設計上、Heroのデータの変更は適当ではない・予想していない
 */
class PlayerHero
{
public:
    PlayerHero(const char* player_label, Hero* hero, PLAYER_HERO_TYPE player_hero_type = PLAYER_HERO_TYPE::PLAYER);
    PLAYER_HERO_TYPE type;

    // prevent memory leak
    PlayerHero(const PlayerHero&) = delete;
    PlayerHero& operator=(const PlayerHero&) = delete;
    PlayerHero(PlayerHero&&) noexcept = default;
    PlayerHero& operator=(PlayerHero&&) noexcept = default;
    virtual ~PlayerHero() = default;

    const char* get_player_label() const { return player_label_; }

    const char* get_name() const { return hero_->get_name(); }
    int get_hp() const { return hp_; }
    int get_max_hp() const { return hero_->get_scaled_ability().hp; }
    int get_shield() const { return shield_; }

    const std::vector<const Card*>& get_available_cards() const;
    const Card* get_card(const int index) const;

    int get_attack() const { return (hero_->get_scaled_ability().attack); }
    int get_defense() const { return (hero_->get_scaled_ability().defense); }

    void take_damage(int power);
    void take_heal(int power);
    void take_shield(int power);

    int get_experience() const { return hero_->get_experience(); }
    void gain_experience(int exp) const { hero_->gain_experience(exp); }

    constexpr static int MAX_SHIELD = 256;

    virtual const Card* select_card() const;

protected:
    char player_label_[PLAYER_LABEL_NAME_MAX_LENGTH];
    Hero* hero_;

    std::vector<const Card*> available_cards_;

    int hp_;
    int shield_ = 0;

    void initialize_cards();
};

/**
 * @class   PlayerHeroAI
 * @brief   COMプレイヤーの実装
 * バトルの行動が自動にできるように
 */
class PlayerHeroAI : public PlayerHero
{
public:
    PlayerHeroAI(const char* player_label, Hero* hero): PlayerHero(player_label, hero, PLAYER_HERO_TYPE::COM)
    {
    }

    const Card* select_card() const override;
};

#endif // PlayerHero_H
