#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "view.h"
#include "Session.h"
#include "Exception.h"

void GameManager::start()
{
    bool is_continue = true;

    try
    {
        Session::get_instance().load();
    } catch (const exception::io::FileInputFailedException&)
    {
        view::flow::initialize_save::save_data_not_found_message();
        initialize_save_flow();
    } catch (const std::exception&)
    {
        throw;
    }

    while (is_continue)
    {
        view::flow::menu::show_main_menu();
        
        int user_input = -1;
        //TODO: input validation
        std::cin >> user_input;
        view::format_line::show_block_separator();
        
        switch (user_input)
        {
        case 1:
            {
                Character character = start_summon_flow();
                add_character_to_session_flow(character);
            
                view::message::key_back_to_menu_message();
                std::cin.ignore();
                std::cin.get();
                break;
            }
        case 2:
            // TODO: 2 Player Battle
            break;    
        case 9:
            is_continue = false;
            break;
        default:
            break;
        }
        view::format_line::show_block_separator();
    }

    view::flow::menu::end_message();
    std::cin.get();
}

// flow control
Character GameManager::start_summon_flow()
{
    char name[Character::NAME_MAX_LENGTH];

    view::flow::summon::title();

    // TODO: clear buffer
    view::flow::summon::name_input_message();
    std::cin >> name;
    
    view::flow::summon::result_message(*name);
    
    view::flow::summon::profile_title();
    const Character summoned_character(name);
    view::character::show_profile(summoned_character);

    return summoned_character;
}

void GameManager::add_character_to_session_flow(const Character& character)
{
    view::flow::summon::saving_menu();
    
    int saving_option = 0;
    std::cin >> saving_option;
    
    switch (saving_option)
    {
    case 1:
        Session::get_instance().add_character(character);
        Session::get_instance().save();
        break;
    case 2:
    default:
        break;
    }
}

void GameManager::initialize_save_flow()
{
    view::flow::initialize_save::welcome_message();

    Character character = GameManager::start_summon_flow();
    Session::get_instance().add_character(character);
    Session::get_instance().save();
    
    view::flow::initialize_save::end_message();
}

