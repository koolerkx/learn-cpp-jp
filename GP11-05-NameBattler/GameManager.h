#pragma once
#include "Hero.h"

class GameManager
{
public:
    static void start();

private:
    static Hero start_summon_flow();
    static void add_hero_to_session_flow(Hero&& hero);  // Accept by move
    static void initialize_save_flow();
    static void hero_menu_flow();
};