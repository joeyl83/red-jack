#ifndef BOARD_H
#define BOARD_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/array.hpp>
#include "card_data.h"

using namespace godot;

class Board : public Object
{
    GDCLASS(Board, Object);

    private:
        Array cards;
        int revealed_count;

    protected:
        static void _bind_methods();


    public:
        Board();
        void add_card(CardData *card);
        void reveal_flop();
        void reveal_turn();
        void reveal_river();

        Array get_all_cards() const;
        Array get_revealed_cards() const;
};

#endif