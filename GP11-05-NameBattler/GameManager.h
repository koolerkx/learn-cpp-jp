#pragma once

class Game {
public:
    static void start();
    
    Game() = delete;    // all member function should be static to access
    
private:
    static void start_summon_flow();
};