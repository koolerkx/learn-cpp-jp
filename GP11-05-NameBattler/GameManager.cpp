#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "view.h"
#include "Session.h"


void Game::start()
{
    bool is_continue = true;

    // TODO: if no save
    initialize_save_flow();

    while (is_continue)
    {
        view::menu::show_main_menu();
        
        int user_input = -1;
        //TODO: input validation
        std::cin >> user_input;
        view::menu::show_session_separator();
        
        switch (user_input)
        {
        case 1:
            // TODO: New Character
            start_summon_flow();
            view::menu::hint_back_to_menu();
            std::cin.ignore();
            std::cin.get();

            // TODO: Save Option
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
        view::menu::show_session_separator();
    }

    std::cout << "Game End" << "\n";
    std::cin.get();
}

// flow control
Character Game::start_summon_flow()
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

    return summoned_character;
}

void Game::initialize_save_flow()
{
    view::menu::show_initialize_welcome_message();

    Character character = Game::start_summon_flow();
    Session::get_instance().add_character(character);
    Session::get_instance().save();
    
    view::menu::show_initialize_departure_message();
}

