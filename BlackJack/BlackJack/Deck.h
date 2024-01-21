#pragma once
#include "Card.h"
#include "Node.h"
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
    Node<Card>* at(int index);
    Node<Card>* operator[](int index);
    Node<Card> front() const;
    Node<Card> getCard();
    void setCard(int value);
private:
    Node<Card>* head;
    Node<Card>* tail;
    int count_deck;
};

