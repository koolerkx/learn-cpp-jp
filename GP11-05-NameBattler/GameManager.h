#pragma once

class Game {
private:
    Game() = default;

    // display
    void show_menu();

public:
    static Game& get_instance();
    void execute();
};