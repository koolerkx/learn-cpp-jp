#pragma once
#include "Hero.h"

constexpr const char* PLAYER_1_LABEL = "P1";
constexpr const char* PLAYER_2_LABEL = "P2";
constexpr const char* PLAYER_COM_LABEL = "COM";

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
    void handle_battle();
    void handle_ai_battle();

    // Hero management
    void handle_hero_list() const;
    void handle_hero_detail() const;
    void handle_hero_delete();

    // Hero state
    Hero make_hero() const;
    std::vector<Hero> hero_;

    void add_hero(Hero&& hero); // Accept by move
    void delete_hero(int index);

    const Hero* get_heroes() const;
    int get_heroes_count() const;

    // Battle
    const Hero* select_hero(const char* player_label) const;

    // File SL
    void save() const;
    void load();
};
