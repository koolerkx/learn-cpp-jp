#pragma once
#include "Hero.h"

class GameManager {
public:
    static void start();

    GameManager() = delete;    // all member function should be static to access
private:
    static Hero start_summon_flow();
    static void initialize_save_flow();
    static void add_hero_to_session_flow(const Hero& hero);

    static void hero_menu_flow();
};