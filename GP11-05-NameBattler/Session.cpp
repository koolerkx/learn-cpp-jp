#include "Session.h"

#include <exception>
#include "Character.h"
#include "view.h"
#include "GameManager.h"

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

