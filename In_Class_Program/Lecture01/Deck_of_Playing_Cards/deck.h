//
// Created by SooYeon Kim on 2018-03-29.
//

#ifndef DECK_OF_PLAYING_CARDS_DECK_H
#define DECK_OF_PLAYING_CARDS_DECK_H

#include "card.h"
#include "hand.h"
const int CARDS_IN_DECK = 52;

class Deck {
public:
    Deck();
    ~Deck();

    Card DealSingleCard();
    Hand DealHand(int number);
    void Shuffle();
    void Cut();
    int CountCardsRemaining();
    void ReturnHand(Hand theHand);
    void ReturnCard(Card theCard);
    int CountValuesRemaining(int val);
    int CountSuitsRemaining(Suit suit);
    bool isEmpty();
    bool isComplete();

private:
    Card deck[CARDS_IN_DECK];
};


#endif //DECK_OF_PLAYING_CARDS_DECK_H
