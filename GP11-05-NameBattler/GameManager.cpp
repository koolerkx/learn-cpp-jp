#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "view.h"
#include "Session.h"
#include "exception.h"
#include "utils.h"

void GameManager::start()
{
    bool is_continue = true;

    try
    {
        Session::get_instance().load();
    }
    catch (const exception::io::FileInputFailedException&)
    {
        view::flow::initialize_save::save_data_not_found_message();
        initialize_save_flow();
    }

    while (is_continue)
    {
        view::flow::menu::show_main_menu();
        constexpr int valid_options[] = {1, 2, 3, 9};

        int selected = utils::input::validated_input(
            utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
            view::flow::menu::option_message
        );
        view::format_line::show_block_separator();

        switch (selected)
        {
        case 1:
            {
                Character character = start_summon_flow();
                add_character_to_session_flow(character);

                view::message::press_any_key();
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

    view::flow::menu::game_end_message();
    std::cin.get();
}

// flow control
Character GameManager::start_summon_flow()
{
    char name[Character::NAME_MAX_LENGTH];

    view::flow::summon::title();

    view::flow::summon::name_input_message();

    std::cin.getline(name, Character::NAME_MAX_LENGTH);

    view::flow::summon::result_message(name);

    view::flow::summon::profile_title();
    const Character summoned_character(name);
    view::character::show_profile(summoned_character);

    return summoned_character;
}

void GameManager::add_character_to_session_flow(const Character& character)
{
    view::flow::summon::saving_menu();

    constexpr int valid_options[] = {1, 2};

    int selected = utils::input::validated_input(
        utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
        view::flow::summon::saving_menu_option_message
    );

    switch (selected)
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
