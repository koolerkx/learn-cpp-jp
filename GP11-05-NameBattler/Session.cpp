#include "Session.h"
#include <iostream>

#include <fstream>
#include "cstring"
#include "Character.h"
#include "utils.h"
#include "Exception.h"

struct SaveData
{
    char characters_names[Character::NAME_MAX_LENGTH][Session::MAX_CHARACTER];
    int characters_count;
};

Session& Session::get_instance()
{
    static Session instance;
    return instance;
}

void Session::add_character(const Character& character)
{
    if (characters_.size() >= Session::MAX_CHARACTER)
    {
        throw exception::character::CharacterLimitExceedException();
    }

    characters_.emplace_back(character);
}

void Session::delete_character(const unsigned int index)
{
    if (index >= characters_.size())
    {
        return;
    }
    characters_.erase(characters_.begin() + index);
}

const Character* Session::get_characters() const
{
    return characters_.data();
}

// fixme: handle overflow
int Session::get_characters_count() const
{
    return static_cast<int>(characters_.size());
}

void Session::save() const
{
    SaveData save_data{
        {},
        get_characters_count(),
    };

    const Character* characters = get_characters();
    for (uint i = 0; i < characters_.size(); i++)
    {
        strncpy_s(save_data.characters_names[i], Character::NAME_MAX_LENGTH, characters[i].get_name(), Character::NAME_MAX_LENGTH);
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
    for (int i = 0; i < save_data.characters_count; i++)
    {
        characters_.emplace_back(save_data.characters_names[i]);
    }

    ifs.close();
}
