#include "../include/hand.h"
#include "../include/card_data.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Hand::Hand()
{
    cards.clear();
}

void Hand::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("add_card", "card"), &Hand::add_card);
    ClassDB::bind_method(D_METHOD("clear"), &Hand::clear);
    ClassDB::bind_method(D_METHOD("get_cards"), &Hand::get_cards);
    ClassDB::bind_method(D_METHOD("size"), &Hand::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &Hand::is_empty);
    ClassDB::bind_method(D_METHOD("is_complete"), &Hand::is_complete);
}

void Hand::add_card(CardData *card)
{
    if(size() >= 2)
    {
        UtilityFunctions::print("Hand is already complete. Cannot add more cards.");
        return;
    }

    if (card)
    {
        cards.append(card);
    }
    else
    {
        UtilityFunctions::print("Cannot add a null card to the hand.");
    }
}

void Hand::clear()
{
    cards.clear();
}

Array Hand::get_cards() const
{
    return cards;
}

int Hand::size() const
{
    return cards.size();
}

bool Hand::is_empty() const
{
    return cards.size() == 0;
}

bool Hand::is_complete() const
{
    return cards.size() == 2;
}
