#pragma once
#include "Card.h"
#include <vector>
#include <memory>

struct Ability
{
    int hp;
    int attack;
    int defense;
    int speed;
};

class Hero
{
public:
    Hero(const char* name);
    ~Hero() = default;

    // only allow to move to prevent memory leak
    Hero(const Hero&) = delete;
    Hero& operator=(const Hero&) = delete;
    Hero(Hero&&) noexcept = default;
    Hero& operator=(Hero&&) noexcept = default;

    int get_rate() const;
    const char* get_name() const;
    Ability get_ability() const;

    const std::vector<std::unique_ptr<Card>>& get_cards() const;
    int get_cards_size() const;

    static constexpr int NAME_MAX_LENGTH = 256;
    static constexpr int ABILITY_MAX_VALUE = 256;
    static constexpr int MAX_CARDS = 5;

private:
    char name_[NAME_MAX_LENGTH];
    unsigned int seed_;
    std::vector<std::unique_ptr<Card>> cards_;
    
    Ability ability_;
    
    void generate_cards();
};