#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "view.h"

void Game::start()
{
    bool is_continue = true;

    while (is_continue)
    {
        view::menu::show_main_menu();
        
        int user_input = -1;
        //TODO: input validation
        std::cin >> user_input;
        std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n";
        
        switch (user_input)
        {
        case 1:
            // TODO: New Character
            start_summon_flow();
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
        std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n";
    }

    std::cout << "Game End" << "\n";
    std::cin.get();
}

// flow control
void Game::start_summon_flow()
{
    char name[Character::NAME_MAX_LENGTH];

    view::menu::show_summon_title();
    // TODO: clear buffer
    std::cout << "キャラの名前を呼んでください：";

    std::cin >> name;
    
    std::cout << "\n結果：『" << name << "』が成功に召喚された！\n\n";

    view::menu::show_summon_profile_title();
    
    const Character summoned_character(name);
    view::character::show_profile(summoned_character);

    view::menu::hint_back_to_menu();
    std::cin.ignore();
    std::cin.get();
}

