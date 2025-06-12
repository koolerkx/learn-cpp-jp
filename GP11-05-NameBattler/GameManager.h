/**
 * @file    GameManager.h
 * @brief   ゲームの進行
 * @author  KOOLER FAN
 * @date    2025-06-12
 */

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Hero.h"

constexpr const char* PLAYER_1_LABEL = "P1";
constexpr const char* PLAYER_2_LABEL = "P2";
constexpr const char* PLAYER_COM_1_LABEL = "COM1";
constexpr const char* PLAYER_COM_2_LABEL = "COM2";

/**
 * @class   GameManager
 * @brief   ゲームの進行、状態、プレイヤーのデータを管理する
 */
class GameManager
{
public:
    static GameManager& get_instance();

    void start_loop();

    static constexpr int MAX_HERO = 5;

private:
    GameManager() = default;

    void initialize_save();
    void save_hero(Hero&& hero); // Accept by move

    // menu behaviour
    void handle_hero_summon();
    void handle_hero_management();
    void handle_p2p_battle();
    void handle_p2c_battle();
    void handle_c2c_battle();
    void handle_battle_tower();

    // Hero management
    void handle_hero_list() const;
    void handle_hero_detail() const;
    void handle_hero_delete();

    // Hero state
    Hero make_hero() const;
    std::vector<Hero> hero_;

    void add_hero(Hero&& hero); // Accept by move
    void delete_hero(int index);

    Hero* get_heroes();
    const Hero* get_heroes() const;
    int get_heroes_count() const;

    // Battle
    Hero* select_hero(const char* player_label);

    // File SL
    void save() const;
    void load();
};

#endif // GAME_MANAGER_H
