#pragma once
#include "Card.h"
#include <vector>
#include <string>
class Deck
{
public:
    Deck(int count_deck);
    ~Deck();
    void push(int rank, int value);
    void push(Card card);
    void pop();
    bool is_empty() const;
    void init(int count_deck);
    Card* at(int index);
    Card* operator[](int index);
    Card front() const;
    Card getCard();
    void setCard(int value);

    void print() const { Card* cur = head; while (cur) { cout << cur->getRank() << ' '; cur = cur->getNext(); } cout << endl; }
private:
    Card* head;
    Card* tail;
    int count_deck;
};

