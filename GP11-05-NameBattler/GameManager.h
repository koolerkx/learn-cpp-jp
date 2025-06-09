#pragma once
#include "Hero.h"

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

    // Hero management
    static void handle_hero_list();
    static void handle_hero_detail();
    static void handle_hero_delete();
    
    // Hero state
    static Hero make_hero();
};