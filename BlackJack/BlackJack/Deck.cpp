#include "Deck.h"

Deck::Deck(int count_deck) : count_deck(count_deck) { init(count_deck); }

Deck::~Deck()
{
    while (!is_empty())
        pop();
}

void Deck::push(int rank, int value)
{
    Card* temp = new Card(rank, value, head);
    if (head) head->setPrev(temp);
    else tail = temp;
    head = temp;
}

void Deck::push(Card card)
{
    push(card.getRank(), card.getValue());
}

void Deck::pop()
{
    if (!head) return;
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Card* temp = head;
    head->setPrev(nullptr);
    head = head->getNext();
    delete temp;
}

bool Deck::is_empty() const { 
    if (head) return 0;
    else return 1;
}

void Deck::init(int count_deck)
{
    vector<Card> NotShuffled_Deck;
    for (int i = 0; i < count_deck; i++) {
        for (int j = 0; j < 4; j++) {
            for (int rank = 2, value = 2; rank != 15; rank++, value++) {
                if (rank >= 11 && rank <= 13) value = 10;
                NotShuffled_Deck.push_back(Card(rank, value));
            }
        }
    }
    int r_index;
    for (int i = 0; i < count_deck; i++) {
        for (int j = 0; j < 52; j++) {
            r_index = rand() % NotShuffled_Deck.size();
            push(NotShuffled_Deck[r_index]);
            NotShuffled_Deck.erase(NotShuffled_Deck.begin() + r_index);
        }
    }
}

Card* Deck::at(int index)
{
    int n = 0;
    Card* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

Card* Deck::operator[](int index)
{
    int n = 0;
    Card* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

Card Deck::front() const
{
    return *head;
}

Card Deck::getCard()
{
    Card card = front();
    pop();
    return card;
}

void Deck::setCard(int value)
{
    head->setValue(value);
}
