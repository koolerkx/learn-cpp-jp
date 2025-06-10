#include "PlayerHero.h"

#include <memory>
#include <vector>
#include <algorithm>
#include <cstring>

#include "utils.h"
#include "view.h"

PlayerHero::PlayerHero(const char* player_label, const Hero* hero)
{
    strncpy_s(
        player_label_, PLAYER_LABEL_NAME_MAX_LENGTH,
        player_label, PLAYER_LABEL_NAME_MAX_LENGTH
    );
    hero_ = hero;

    hp_ = hero->get_ability().hp;

    initialize_cards();
}

void PlayerHero::initialize_cards()
{
    const std::vector<std::unique_ptr<Card>>& hero_cards = hero_->get_cards();
    available_cards_.reserve(hero_cards.size());

    for (const std::unique_ptr<Card>& card : hero_cards)
    {
        available_cards_.push_back(card.get());
    }
}

const std::vector<const Card*>& PlayerHero::get_available_cards() const
{
    return available_cards_;
}

const Card* PlayerHero::get_card(const int index) const
{
    if (index >= 0 && index < static_cast<int>(available_cards_.size()))
    {
        return available_cards_[index];
    }
    return nullptr;
}

void PlayerHero::take_damage(const int power)
{
    const int applied_damage = std::max(0, power - shield_);
    shield_ = std::max(0, shield_ - power);

    hp_ = std::max(0, hp_ - applied_damage);
}

void PlayerHero::take_heal(const int power)
{
    const int applied_heal = std::max(0, power);
    const int max_hp = get_max_hp();

    hp_ = std::min(max_hp, hp_ + applied_heal);
}

void PlayerHero::take_shield(const int power)
{
    const int applied_shield = shield_ + std::max(0, power);
    shield_ = std::min(applied_shield, PlayerHero::MAX_SHIELD);
}

const Card* PlayerHero::select_card() const
{
    int selected = utils::input::validated_input(
        utils::input::validator::is_in_range(1, static_cast<int>(get_available_cards().size())),
        view::flow::battle::battle_round_option_message
    );
    view::format_line::blank();

    return get_card(selected - 1);
}

const Card* PlayerHeroAI::select_card() const
{
    view::format_line::blank();

    std::vector<float> cards_score;

    int card_idx = 0;
    int selected = 0;
    float selected_score = -1;

    for (const Card* card : get_available_cards())
    {
        float score = card->calculate_score(*this);

        // random factor from -30% to +30%
        score *= (1.0f + static_cast<float>(utils::random(0, 60) - 20) / 100.0f);

        cards_score.push_back(score);

        if (cards_score[card_idx] > selected_score)
        {
            selected = card_idx;
            selected_score = cards_score[card_idx];
        }
        card_idx++;
    }

    return get_card(selected);
}
