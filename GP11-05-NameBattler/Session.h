#pragma once
#include <vector>
#include "Hero.h"

class Session
{
public:
    static Session& get_instance();

    void add_hero(Hero&& hero);  // Accept by move
    void delete_hero(unsigned int index);

    const Hero* get_heroes() const;
    int get_heroes_count() const;

    void save() const;
    void load();

    static constexpr int MAX_HERO = 5;

private:
    Session() = default;  // Private constructor for singleton
    std::vector<Hero> hero_;
};