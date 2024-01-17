#pragma once
#include <iostream>
using namespace std;
class Card
{
public:
	explicit Card(int rank, int value, Card* next = nullptr, Card* prev = nullptr);
	int getRank() const;
	void setValue(int v);
	int getValue() const;
	void setNext(Card* n);
	Card* getNext() const;
	void setPrev(Card* p);
	Card* getPrev() const;
	void printRank() const;
private:
	int rank;
	int value;
	Card* next;
	Card* prev;
};

