#include <cstdlib>
#include "cstring"
#include "Hero.h"

#include <cmath>

#include "utils.h"
#include <memory>

Hero::Hero(const char* name)
{
    strncpy_s(name_, name, Hero::NAME_MAX_LENGTH);

    seed_ = utils::hash_chars(name_);

    srand(seed_);

    ability_ = {
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
        rand() % ABILITY_MAX_VALUE,
    };

    cards_.reserve(MAX_CARDS);

    generate_cards();
}

const char* Hero::get_name() const
{
    return name_;
}

Ability Hero::get_ability() const
{
    return ability_;
}

Ability Hero::get_scaled_ability() const
{
    float scaler = hero_level::get_ability_scaler(hero_level::get_level(experience_));
    Ability ability = {
        static_cast<int>(static_cast<float>(ability_.attack) * scaler),
          static_cast<int>(static_cast<float>(ability_.defense) * scaler),
          static_cast<int>(static_cast<float>(ability_.hp) * scaler)
    };
    return ability;
}


const std::vector<std::unique_ptr<Card>>& Hero::get_cards() const
{
    return cards_;
}

int Hero::get_cards_size() const
{
    return static_cast<int>(cards_.size());
}

int Hero::get_rate() const
{
    return ability_.attack + ability_.defense + ability_.hp;
}

void Hero::generate_cards()
{
    srand(seed_);

    constexpr int num_cards = MAX_CARDS;

    for (int i = 0; i < num_cards && cards_.size() < MAX_CARDS; i++)
    {
        CARD_TYPE card_type = static_cast<CARD_TYPE>(rand() % 3);

        switch (card_type)
        {
        case CARD_TYPE::ATTACK:
            {
                int power = (ability_.attack / 4) + (rand() % 20) + 5;
                cards_.emplace_back(std::make_unique<AttackCard>(power));
                break;
            }
        case CARD_TYPE::HEAL:
            {
                int power = (ability_.hp / 8) + (rand() % 15) + 3;
                cards_.emplace_back(std::make_unique<HealCard>(power));
                break;
            }
        case CARD_TYPE::DEFENSE:
            {
                int power = (ability_.defense / 6) + (rand() % 12) + 2;
                cards_.emplace_back(std::make_unique<DefenseCard>(power));
                break;
            }
        }
    }
}

int Hero::get_experience() const
{
    return experience_;
}

void Hero::gain_experience(int exp)
{
    experience_ += exp;
}


namespace hero_level
{
    int get_level(int exp)
    {
        // レベル二次曲線の逆関数
        // inverse function of level formula
        int lv = static_cast<int>(std::floor(std::sqrt(static_cast<float>(exp) / static_cast<float>(base) + 1.0f)));
        return std::max(1, std::min(lv, MAX_LEVEL));
    }

    // 戦闘はレベルアップまで必要な経験値の８％、レベル1は最大能力値の0.5倍
    // each battle gain 8% of experience of level up required
    int get_expected_experience_for_battle(int level)
    {
        const std::function<float(int)> totalExp = [=](const int lv)
        {
            return static_cast<float>(
                (lv <= 1) ? 0.0f : base * (std::pow(lv, slope) - 1.0f)
            );
        };

        return static_cast<int>(
            std::ceil(0.08f * totalExp(level + 1) - totalExp(level))
        );
    }

    float get_ability_scaler(int level)
    {
        return LEVEL_SCALE_MIN +
            (LEVEL_SCALE_MAX - LEVEL_SCALE_MIN) *
            ((static_cast<float>(level) - 1) / (MAX_LEVEL - 1));
    }
}
