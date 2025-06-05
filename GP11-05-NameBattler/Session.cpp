#include "Session.h"
#include <iostream>

#include <fstream>
#include "cstring"
#include "Hero.h"
#include "utils.h"
#include "Exception.h"

struct SaveData
{
    char hero_names[Session::MAX_HERO][Hero::NAME_MAX_LENGTH];
    int hero_count;
};

Session& Session::get_instance()
{
    static Session instance;
    return instance;
}

void Session::add_hero(const Hero& hero)
{
    if (hero_.size() >= Session::MAX_HERO)
    {
        throw exception::hero::HeroLimitExceedException();
    }

    hero_.emplace_back(hero);
}

void Session::delete_hero(const unsigned int index)
{
    if (index >= hero_.size())
    {
        return;
    }
    hero_.erase(hero_.begin() + index);
}

const Hero* Session::get_heroes() const
{
    return hero_.data();
}

// fixme: handle overflow
int Session::get_heroes_count() const
{
    return static_cast<int>(hero_.size());
}

void Session::save() const
{
    SaveData save_data{
        {},
        get_heroes_count(),
    };

    const Hero* heroes = get_heroes();
    for (uint i = 0; i < hero_.size(); i++)
    {
        strncpy_s(save_data.hero_names[i], Hero::NAME_MAX_LENGTH, heroes[i].get_name(), Hero::NAME_MAX_LENGTH);
    }

    // TODO: Failed to open save
    std::ofstream ofs("save.dat", std::ios::binary);
    if (!ofs.is_open())
    {
        throw exception::io::FileOutputFailedException();
    }
    ofs.write(reinterpret_cast<const char*>(&save_data), sizeof(SaveData));
    ofs.close();
}

void Session::load()
{
    std::ifstream ifs("save.dat", std::ios::binary);
    if (!ifs.is_open())
    {
        throw exception::io::FileInputFailedException();
    }

    SaveData save_data{};
    ifs.read(reinterpret_cast<char*>(&save_data), sizeof(SaveData));
    for (int i = 0; i < save_data.hero_count; i++)
    {
        hero_.emplace_back(save_data.hero_names[i]);
    }

    ifs.close();
}
