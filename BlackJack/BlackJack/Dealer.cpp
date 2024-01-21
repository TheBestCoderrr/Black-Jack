#include "Dealer.h"

vector<Card> Dealer::getHand() const
{
	return hand;
}

void Dealer::Hit(Deck& deck)
{
	if (deck.is_empty()) deck.init(6);
	if (deck.getCard().getValue().getRank() == 14 && getSum() + deck.getCard().getValue().getValue() > 21) deck.setCard(1);
	hand.push_back(deck.getCard().getValue());
}

void Dealer::CheckHand() const
{
	cout << "Cards: ";
	for (int i = 0; i < hand.size(); i++) {
		hand[i].printRank();
	}
	cout << endl;
}

int Dealer::getSum() const
{
	int sum = 0;
	for (int i = 0; i < hand.size(); i++)
		sum += hand[i].getValue();
	return sum;
}

void Dealer::clear()
{
	hand.clear();
}

