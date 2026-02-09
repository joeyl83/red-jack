#ifndef HAND_H
#define HAND_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/array.hpp>
#include "card_data.h"

using namespace godot;

class Hand : public Object
{
    GDCLASS(Hand, Object);

private:
    Array cards;

protected:
    static void _bind_methods();

public:
    Hand();
    void add_card(CardData *card);
    void clear();
    Array get_cards() const;
    int size() const;
    bool is_empty() const;
    bool is_complete() const;
};

#endif