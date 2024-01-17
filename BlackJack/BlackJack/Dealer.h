#pragma once
#include "Deck.h"
class Dealer 
{
public:
	vector<Card> getHand() const;
	void Hit(Deck& deck);
	void CheckHand() const;
	int getSum() const;
	void clear();
private:
	vector<Card> hand;
};

