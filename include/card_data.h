#ifndef CARD_DATA_H
#define CARD_DATA_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class CardData : public Object
{
    GDCLASS(CardData, Object);

public:
    enum Suit
    {
        HEARTS = 0,
        DIAMONDS,
        CLUBS,
        SPADES
    };

    enum Rank
    {
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 11,
        QUEEN = 12,
        KING = 13,
        ACE = 14
    };

private:
    Suit suit;
    Rank rank;
    int base_value;
    String texture_path;

protected:
    static void _bind_methods();

public:
    CardData();
    CardData(Suit p_suit, Rank p_rank, const String &p_texture_path);

    Suit get_suit() const;
    Rank get_rank() const;
    int get_base_value() const;
    String get_texture_path() const;
};

VARIANT_ENUM_CAST(CardData::Suit);
VARIANT_ENUM_CAST(CardData::Rank);

#endif