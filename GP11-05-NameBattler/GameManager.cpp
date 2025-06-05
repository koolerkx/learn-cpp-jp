#include <iostream>
#include "GameManager.h"
#include "Hero.h"
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
        constexpr int valid_options[] = {1, 2, 3, 4, 9};

        int selected = utils::input::validated_input(
            utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
            view::flow::menu::option_message
        );

        switch (selected)
        {
        case 1:
            {
                Hero hero = start_summon_flow();
                add_hero_to_session_flow(hero);

                view::message::press_any_key();
                std::cin.get();
                break;
            }
        case 2:
            // TODO: 2 Player Battle
            break;
        case 4:
            hero_menu_flow();
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
Hero GameManager::start_summon_flow()
{
    char name[Hero::NAME_MAX_LENGTH];

    view::flow::summon::title();

    view::flow::summon::name_input_message();

    std::cin.getline(name, Hero::NAME_MAX_LENGTH);

    view::flow::summon::result_message(name);

    view::flow::summon::profile_title();
    const Hero summoned_hero(name);
    view::hero::show_profile(summoned_hero);

    return summoned_hero;
}

void GameManager::add_hero_to_session_flow(const Hero& hero)
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
        Session::get_instance().add_hero(hero);
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

    Hero hero = GameManager::start_summon_flow();
    Session::get_instance().add_hero(hero);
    Session::get_instance().save();

    view::flow::initialize_save::end_message();
}

void GameManager::hero_menu_flow()
{
    view::flow::hero::hero_management_menu();

    int valid_options[] = {1, 2, 3, 9};
    int selected = utils::input::validated_input(
        utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
        view::flow::hero::hero_menu_option_message
    );

    Session session = Session::get_instance();

    switch (selected)
    {
    case 2:
        {
            view::flow::hero::hero_detail_title();
            view::hero::show_list(session.get_heroes(), session.get_heroes_count());

            int selected_hero = utils::input::validated_input(
                utils::input::validator::is_in_range(1, session.get_heroes_count()),
                view::flow::hero::hero_detail_option_message
            );

            view::flow::summon::profile_title();
            view::hero::show_profile(session.get_heroes()[selected_hero - 1]);

            view::message::press_any_key();
            std::cin.get();
            break;
        }
    case 3:
        {
            view::flow::hero::hero_delete_title();
            view::hero::show_list(session.get_heroes(), session.get_heroes_count());

            int selected_hero = utils::input::validated_input(
                utils::input::validator::is_in_range(1, session.get_heroes_count()),
                view::flow::hero::hero_delete_option_message
            );

            session.delete_hero(selected_hero - 1);
            const char* hero_to_delete_name = session.get_heroes()[selected_hero - 1].get_name();
            session.save();
            view::flow::hero::hero_delete_result_message(hero_to_delete_name);

            view::message::press_any_key();
            std::cin.get();
            break;
        }
    case 1:
    default:
        {
            view::flow::hero::hero_list_title();
            view::hero::show_list(session.get_heroes(), session.get_heroes_count());

            view::message::press_any_key();
            std::cin.get();
            break;
        }
    }
}
