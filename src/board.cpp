#include "../include/board.h"

using namespace godot;

Board::Board()
{
    cards.clear();
    revealed_count = 0;
}

void Board::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("add_card", "card"), &Board::add_card);
    ClassDB::bind_method(D_METHOD("reveal_flop"), &Board::reveal_flop);
    ClassDB::bind_method(D_METHOD("reveal_turn"), &Board::reveal_turn);
    ClassDB::bind_method(D_METHOD("reveal_river"), &Board::reveal_river);
    ClassDB::bind_method(D_METHOD("get_all_cards"), &Board::get_all_cards);
    ClassDB::bind_method(D_METHOD("get_revealed_cards"), &Board::get_revealed_cards);
}

void Board::add_card(CardData *card)
{
    if (cards.size() >= 5)
    {
        UtilityFunctions::print("Board already has 5 cards. Cannot add more.");
        return;
    }

    if (card)
    {
        cards.append(card);
    }
    else
    {
        UtilityFunctions::print("Cannot add a null card to the board.");
    }
}

void Board::reveal_flop()
{
    if (cards.size() < 3)
    {
        UtilityFunctions::print("Not enough cards on the board to reveal the flop.");
        return;
    }
    revealed_count = 3;
}

void Board::reveal_turn()
{
    if (cards.size() < 4)
    {
        UtilityFunctions::print("Not enough cards on the board to reveal the turn.");
        return;
    }
    revealed_count = 4;
}

void Board::reveal_river()
{
    if (cards.size() < 5)
    {
        UtilityFunctions::print("Not enough cards on the board to reveal the river.");
        return;
    }
    revealed_count = 5;
}

Array Board::get_all_cards() const
{
    return cards;
}

Array Board::get_revealed_cards() const
{
    Array revealed_cards;
    for (int i = 0; i < revealed_count && i < cards.size(); i++)
    {
        revealed_cards.append(cards[i]);
    }
    return revealed_cards;
}