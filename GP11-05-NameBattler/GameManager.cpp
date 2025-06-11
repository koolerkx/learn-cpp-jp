#include "GameManager.h"

#include <iostream>
#include <fstream>

#include "Hero.h"
#include "view.h"
#include "exception.h"
#include "utils.h"

GameManager& GameManager::get_instance()
{
    static GameManager instance;
    return instance;
}

void GameManager::start_loop()
{
    bool is_continue = true;

    try
    {
        load();
    }
    catch (const exception::io::FileInputFailedException&)
    {
        view::flow::initialize_save::save_data_not_found_message();
        initialize_save();
    }

    while (is_continue)
    {
        view::flow::menu::show_main_menu();
        constexpr int valid_options[] = {1, 2, 3, 4, 5, 6, 9};

        int selected = utils::input::validated_input(
            utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
            view::flow::menu::option_message
        );
        view::format_line::blank();

        switch (selected)
        {
        case 1:
            handle_hero_summon();
            break;
        case 2:
            handle_p2p_battle();
            break;
        case 3:
            handle_p2c_battle();
            break;
        case 4:
            handle_c2c_battle();
            break;
        case 5:
            handle_battle_tower();
            break;
        case 6:
            handle_hero_management();
            break;
        case 9:
            is_continue = false;
            break;
        default:
            break;
        }
        view::format_line::block();

        save();
    }

    view::flow::menu::game_end_message();
    std::cin.get();
}

void GameManager::initialize_save()
{
    view::flow::initialize_save::welcome_message();
    view::format_line::blank();

    Hero hero = GameManager::make_hero();
    add_hero(std::move(hero));
    save();

    view::flow::initialize_save::end_message();
}

void GameManager::save_hero(Hero&& hero)
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
        add_hero(std::move(hero));
        save();
        break;
    case 2:
    default:
        break;
    }
}

void GameManager::handle_hero_summon()
{
    Hero hero = make_hero();
    save_hero(std::move(hero));

    view::format_line::blank();
    view::message::press_any_key_menu();
    std::cin.get();
}

void GameManager::handle_hero_management()
{
    view::flow::hero::hero_management_menu();

    constexpr int valid_options[] = {1, 2, 3, 9};
    int selected = utils::input::validated_input(
        utils::input::validator::is_in_list(valid_options, std::size(valid_options)),
        view::flow::hero::hero_menu_option_message
    );
    view::format_line::blank();

    switch (selected)
    {
    case 1:
        handle_hero_list();
        break;
    case 2:
        handle_hero_detail();
        break;
    case 3:
        handle_hero_delete();
        break;
    case 9: default:
        break;
    }

    view::format_line::blank();
    view::message::press_any_key_menu();
    std::cin.get();
}

void GameManager::handle_p2p_battle()
{
    view::flow::battle::battle_p2p_title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    Hero* p1_hero = select_hero(PLAYER_1_LABEL);
    PlayerHero p1 = PlayerHero(PLAYER_1_LABEL, p1_hero);

    Hero* p2_hero = select_hero(PLAYER_2_LABEL);
    PlayerHero p2 = PlayerHero(PLAYER_2_LABEL, p2_hero);

    Battle battle(&p1, &p2);
    battle.run();
}

void GameManager::handle_p2c_battle()
{
    view::flow::battle::battle_p2c_title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    Hero* p1_hero = select_hero(PLAYER_1_LABEL);
    PlayerHero p1 = PlayerHero(PLAYER_1_LABEL, p1_hero);

    int com_selected = utils::random(1, get_heroes_count());

    Hero* com_hero = &get_heroes()[com_selected - 1];
    PlayerHeroAI com = PlayerHeroAI(PLAYER_COM_1_LABEL, com_hero);

    Battle battle(&p1, &com);
    battle.run();
    
    view::flow::battle::end_message();
    view::message::press_any_key_menu();
    std::cin.get();
}

void GameManager::handle_c2c_battle()
{
    view::flow::battle::battle_c2c_title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    Hero* com1_hero = select_hero(PLAYER_COM_1_LABEL);
    PlayerHeroAI com1 = PlayerHeroAI(PLAYER_COM_1_LABEL, com1_hero);

    Hero* com2_hero = select_hero(PLAYER_COM_2_LABEL);
    PlayerHeroAI com2 = PlayerHeroAI(PLAYER_COM_2_LABEL, com2_hero);

    Battle battle(&com1, &com2);
    battle.run();
    
    view::flow::battle::end_message();
    view::message::press_any_key_menu();
    std::cin.get();
}

void GameManager::handle_battle_tower()
{
    view::flow::battle_tower::title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    Hero* p1_hero = select_hero(PLAYER_1_LABEL);
    PlayerHero p1 = PlayerHero(PLAYER_1_LABEL, p1_hero);
    view::format_line::blank();
    
    bool is_continue = true;
    int tower_level = 1;
    constexpr int MAX_TOWER_LEVEL = 10;
    do
    {
        view::flow::battle_tower::next_level_title(tower_level);
        view::format_line::blank();
        
        int com_selected = utils::random(1, get_heroes_count());
        Hero* com_hero = &get_heroes()[com_selected - 1];
        PlayerHeroAI com = PlayerHeroAI(PLAYER_COM_1_LABEL, com_hero);
        Battle battle(&p1, &com);

        is_continue = battle.run();
        tower_level++;
    }
    while (is_continue && tower_level <= MAX_TOWER_LEVEL);

    if (tower_level > MAX_TOWER_LEVEL)
    {
        view::flow::battle_tower::end_message_cleared(tower_level - 1);
    }
    else
    {
        view::flow::battle_tower::end_message(tower_level - 1);
    }
    view::format_line::blank();
    view::message::press_any_key_menu();
    std::cin.get();
}

void GameManager::handle_hero_list() const
{
    view::flow::hero::hero_list_title();
    view::hero::show_list(get_heroes(), get_heroes_count());
}

void GameManager::handle_hero_detail() const
{
    view::flow::hero::hero_detail_title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    view::format_line::blank();
    int selected_hero = utils::input::validated_input(
        utils::input::validator::is_in_range(1, get_heroes_count()),
        view::flow::hero::hero_detail_option_message
    );
    view::format_line::blank();

    view::flow::summon::profile_title();
    view::hero::show_profile(get_heroes()[selected_hero - 1]);
}

void GameManager::handle_hero_delete()
{
    view::flow::hero::hero_delete_title();
    view::hero::show_list(get_heroes(), get_heroes_count());

    int selected_hero = utils::input::validated_input(
        utils::input::validator::is_in_range(1, get_heroes_count()),
        view::flow::hero::hero_delete_option_message
    );
    view::format_line::blank();

    const char* hero_to_delete_name = get_heroes()[selected_hero - 1].get_name();
    delete_hero(selected_hero - 1);
    save();
    view::flow::hero::hero_delete_result_message(hero_to_delete_name);
}

Hero GameManager::make_hero() const
{
    char name[Hero::NAME_MAX_LENGTH];

    view::flow::summon::title();
    view::flow::summon::name_input_message();

    std::cin.getline(name, Hero::NAME_MAX_LENGTH);
    view::format_line::blank();

    view::flow::summon::result_message(name);

    view::format_line::blank();
    view::flow::summon::profile_title();

    Hero summoned_hero(name);
    view::hero::show_profile(summoned_hero);

    return summoned_hero;
}

void GameManager::add_hero(Hero&& hero) // Accept by move
{
    if (hero_.size() >= MAX_HERO)
    {
        throw exception::hero::HeroLimitExceedException();
    }

    hero_.emplace_back(std::move(hero)); // Move into vector
}

void GameManager::delete_hero(int index)
{
    if (index >= static_cast<int>(hero_.size()))
    {
        throw exception::hero::HeroNotExistException();
    }
    hero_.erase(hero_.begin() + index);
}

Hero* GameManager::get_heroes()
{
    return hero_.data();
}

const Hero* GameManager::get_heroes() const
{
    return hero_.data();
}

int GameManager::get_heroes_count() const
{
    return static_cast<int>(hero_.size());
}

Hero* GameManager::select_hero(const char* player_label)
{
    view::flow::battle::player_select_hero(player_label);
    const int selected = utils::input::validated_input(
        utils::input::validator::is_in_range(1, get_heroes_count()),
        view::flow::battle::select_hero_options
    );
    view::format_line::blank();

    return &get_heroes()[selected - 1];
}

struct SaveData
{
    char hero_names[GameManager::MAX_HERO][Hero::NAME_MAX_LENGTH];
    int experience[GameManager::MAX_HERO];
    int hero_count;
};

void GameManager::save() const
{
    SaveData save_data{
        {},
        {},
        get_heroes_count(),
    };

    const Hero* heroes = get_heroes();
    for (uint i = 0; i < hero_.size(); i++)
    {
        strncpy_s(save_data.hero_names[i], Hero::NAME_MAX_LENGTH, heroes[i].get_name(), Hero::NAME_MAX_LENGTH);
        save_data.experience[i] = heroes[i].get_experience();
    }

    std::ofstream ofs("save.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        throw exception::io::FileOutputFailedException();
    }
    ofs.write(reinterpret_cast<const char*>(&save_data), sizeof(SaveData));
    ofs.close();
}

void GameManager::load()
{
    std::ifstream ifs("save.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        throw exception::io::FileInputFailedException();
    }

    SaveData save_data{};
    ifs.read(reinterpret_cast<char*>(&save_data), sizeof(SaveData));

    // データのフォーマットが違う恐れがある
    if (save_data.hero_count <= 0)
    {
        throw exception::io::FileInputFailedException();
    }

    for (int i = 0; i < save_data.hero_count; i++)
    {
        hero_.emplace_back(save_data.hero_names[i]); // Direct construction in vector
        hero_[i].gain_experience(save_data.experience[i]);
    }

    ifs.close();
}
