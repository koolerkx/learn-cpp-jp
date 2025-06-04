#pragma once

class Game {
private:
    Game() = default;

    // menu
    void show_menu();

    void summon_character();
    void show_summon_character_menu();

public:
    static Game& get_instance();
    void execute();
};