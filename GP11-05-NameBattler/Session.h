#pragma once
#include "Hero.h"
#include <vector>

constexpr const char* SESSION_CHARACTERS_MAX_LIMIT_EXCEEDED_EXCEPTION = "characters max limit exceeded";

class Session
{
public:
    static Session& get_instance();
    
    void save() const;
    void load();
    // void initialize_save();

    void add_hero(const Hero& character);
    void delete_hero(unsigned int index);
    const Hero* get_heroes() const;
    int get_heroes_count() const;
    
    static constexpr int MAX_HERO = 5;
    
private:
    Session() = default;
    
    std::vector<Hero> hero_;
};
