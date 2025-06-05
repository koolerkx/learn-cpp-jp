#pragma once
#include "Character.h"

class GameManager {
public:
    static void start();

    GameManager() = delete;    // all member function should be static to access
private:
    static Character start_summon_flow();
    static void initialize_save_flow();
    static void add_character_to_session_flow(const Character& character);
};
