#ifndef DECK_H
#define DECK_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/array.hpp>
#include "card_data.h"

using namespace godot;

class Deck : public Object
{
    GDCLASS(Deck, Object);

private:
    Array cards;

protected:
    static void _bind_methods();

public:
    Deck();
    void shuffle();
    CardData *draw_card();
    void build_deck();
    int size() const;
    bool is_empty() const;
};

#endif