#include "Card.h"

Card::Card(int rank, int value) : rank(rank), value(value) {}

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

void Card::printRank() const
{
	if (getRank() == 11) cout << "J ";
	else if (getRank() == 12) cout << "Q ";
	else if (getRank() == 13) cout << "K ";
	else if (getRank() == 14) cout << "A ";
	else cout << getRank() << ' ';
}
