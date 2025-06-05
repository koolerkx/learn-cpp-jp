#include "Session.h"

#include <fstream>
#include <exception>
#include "cstring"
#include "Character.h"
#include "utils.h"

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
        throw std::exception(SESSION_CHARACTERS_MAX_LIMIT_EXCEEDED_EXCEPTION);
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
    SaveData saveData {
        {},
        Character::NAME_MAX_LENGTH,
    };
    
    const Character* characters = get_characters();
    for (uint i=0; i < characters_.size(); i++)
    {
        strncpy_s(saveData.characters_names[i], characters[i].get_name(), Character::NAME_MAX_LENGTH);
    }

    // TODO: Failed to open save
    std::ofstream ofs("save.dat", std::ios::binary);
    if (ofs.is_open())
    {
        ofs.write(reinterpret_cast<const char*>(&saveData), sizeof(SaveData));
    }
    ofs.close();
}

