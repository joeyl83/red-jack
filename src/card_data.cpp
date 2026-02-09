#include "../include/card_data.h"

using namespace godot;

CardData::CardData()
{
    suit = HEARTS;
    rank = TWO;
    base_value = 2;
    texture_path = "";
}

CardData::CardData(Suit p_suit, Rank p_rank, const String &p_texture_path)
{
    suit = p_suit;
    rank = p_rank;
    base_value = static_cast<int>(p_rank);
    texture_path = p_texture_path;
}

void CardData::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("get_suit"), &CardData::get_suit);
    ClassDB::bind_method(D_METHOD("get_rank"), &CardData::get_rank);
    ClassDB::bind_method(D_METHOD("get_base_value"), &CardData::get_base_value);
    ClassDB::bind_method(D_METHOD("get_texture_path"), &CardData::get_texture_path);

    BIND_ENUM_CONSTANT(SPADES);
    BIND_ENUM_CONSTANT(HEARTS);
    BIND_ENUM_CONSTANT(DIAMONDS);
    BIND_ENUM_CONSTANT(CLUBS);

    BIND_ENUM_CONSTANT(ACE);
    BIND_ENUM_CONSTANT(TWO);
    BIND_ENUM_CONSTANT(THREE);
    BIND_ENUM_CONSTANT(FOUR);
    BIND_ENUM_CONSTANT(FIVE);
    BIND_ENUM_CONSTANT(SIX);
    BIND_ENUM_CONSTANT(SEVEN);
    BIND_ENUM_CONSTANT(EIGHT);
    BIND_ENUM_CONSTANT(NINE);
    BIND_ENUM_CONSTANT(TEN);
    BIND_ENUM_CONSTANT(JACK);
    BIND_ENUM_CONSTANT(QUEEN);
    BIND_ENUM_CONSTANT(KING);
}

CardData::Suit CardData::get_suit() const
{
    return suit;
}

CardData::Rank CardData::get_rank() const
{
    return rank;
}

int CardData::get_base_value() const
{
    return base_value;
}

String CardData::get_texture_path() const
{
    return texture_path;
}

