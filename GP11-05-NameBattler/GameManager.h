#pragma once
#include "Character.h"

class Game {
public:
    static void start();

    Game() = delete;    // all member function should be static to access
private:
    static Character start_summon_flow();
    static void initialize_save_flow();
};
