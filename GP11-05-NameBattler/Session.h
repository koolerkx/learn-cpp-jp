#pragma once
#include "Character.h"
#include <vector>

constexpr const char* SESSION_CHARACTERS_MAX_LIMIT_EXCEEDED_EXCEPTION = "characters max limit exceeded";

class Session
{
public:
    static Session& get_instance();
    
    // void save();
    // void load();
    // void initialize_save();

    void add_character(const Character& character);
    void delete_character(unsigned int index);
    const Character* get_characters() const;
    int get_characters_count() const;
    
    static constexpr int MAX_CHARACTER = 5;
    
private:
    Session() = default;
    
    std::vector<Character> characters_;
};
