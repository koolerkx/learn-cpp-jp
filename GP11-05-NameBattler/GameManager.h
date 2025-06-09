#pragma once
#include "Hero.h"

constexpr const char* PLAYER_1_LABEL = "P1";
constexpr const char* PLAYER_2_LABEL = "P2";
constexpr const char* PLAYER_COM_LABEL = "COM";

class GameManager
{
public:
    static void start_loop();

private:
    static void save_hero(Hero&& hero);  // Accept by move
    static void initialize_save_flow();

    // menu behaviour
    static void handle_hero_summon();
    static void handle_hero_management();
    static void handle_battle();
    static void handle_ai_battle();

    // Hero management
    static void handle_hero_list();
    static void handle_hero_detail();
    static void handle_hero_delete();
    
    // Hero state
    static Hero make_hero();

    // Battle
    const static Hero* select_hero(const char* player_label);
};