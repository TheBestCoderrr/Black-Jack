#include "Card.h"

Card::Card(int rank, int value, Card* next, Card* prev) : rank(rank), value(value), next(next), prev(prev) {}

int Card::getRank() const
{
	return rank;
}

void Card::setValue(int v)
{
	value = v;
}

int Card::getValue() const
{
	return value;
}

void Card::setNext(Card* n)
{
	next = n;
}

Card* Card::getNext() const
{
	return next;
}

void Card::setPrev(Card* p)
{
	prev = p;
}

Card* Card::getPrev() const
{
	return prev;
}

void Card::printRank() const
{
	if (getRank() == 11) cout << "J ";
	else if (getRank() == 12) cout << "Q ";
	else if (getRank() == 13) cout << "K ";
	else if (getRank() == 14) cout << "A ";
	else cout << getRank() << ' ';
}
