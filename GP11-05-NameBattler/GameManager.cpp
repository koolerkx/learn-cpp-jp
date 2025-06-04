#include <iostream>
#include "GameManager.h"

Game& Game::get_instance() {
    static Game instance;

    return instance;
}

void Game::execute()
{
    bool is_continue = true;

    while (is_continue)
    {
        show_menu();
        
        int user_input = -1;
        //TODO: input validation
        std::cin >> user_input;
        
        switch (user_input)
        {
        case 1:
            // TODO: New Character
            break;
        case 2:
            // TODO: 2 Player Battle
            break;    
        case 9:
            is_continue = false;
            break;
        default:
            break;
        }
    }

    std::cout << "Game End" << "\n";
    std::cin.get();
}

void Game::show_menu()
{
    std::cout << "-----Name Battler-----" << "\n";
    std::cout << "なにをしたい？" << "\n";
    std::cout << "1. キャラ召喚" << "\n";
    std::cout << "2. 二人で遊ぶ" << "\n";
    std::cout << "9. 終わる" << "\n";
}



