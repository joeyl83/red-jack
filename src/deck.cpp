#include "../include/deck.h"
#include "../include/card_data.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Deck::Deck(){
    build_deck();
    shuffle();
}

void Deck::_bind_methods(){
    ClassDB::bind_method(D_METHOD("shuffle"), &Deck::shuffle);
    ClassDB::bind_method(D_METHOD("draw_card"), &Deck::draw_card);
    ClassDB::bind_method(D_METHOD("build_deck"), &Deck::build_deck);
    ClassDB::bind_method(D_METHOD("size"), &Deck::size);
    ClassDB::bind_method(D_METHOD("is_empty"), &Deck::is_empty);
}

void Deck::build_deck(){
    cards.clear();
    for(int suit = CardData::HEARTS; suit <= CardData::SPADES; suit++){
        for(int rank = CardData::TWO; rank <= CardData::ACE; rank++){
            String suit_name = (suit == CardData::HEARTS ? "hearts" :
                                suit == CardData::DIAMONDS ? "diamonds" :
                                suit == CardData::CLUBS ? "clubs" : "spades");
            String texture_path = "res://assets/casino/Cards/" + suit_name + "_"
                                   + String::num_int64(rank) + ".png";
            CardData *card = new CardData(static_cast<CardData::Suit>(suit), static_cast<CardData::Rank>(rank), texture_path);
            cards.append(card);
        }
    }
}

void Deck::shuffle(){
    cards.shuffle();
}

bool Deck::is_empty() const{
    return cards.size() == 0;
}

int Deck::size() const{
    return cards.size();
}

CardData* Deck::draw_card(){
    if(is_empty()){
        UtilityFunctions::print("Deck is empty! Cannot draw a card.");
        return nullptr;
    }
    CardData *card = Object::cast_to<CardData>(cards.back());
    cards.pop_back();   
    return card;
}