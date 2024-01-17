#pragma once
#include "Dealer.h"
class Player
{
public:
	Player(string name, double bank);
	string getName() const;
	double getBalance() const;
	void setBalance(double balance);
	double getBank() const;
	void setBank(double bank);

	void Hit(Deck& deck);
	void Stand();
	void Split(Deck& deck, const Dealer dealer);
	void Double(Deck& deck);
	void Surrender();
	void CheckHand() const;
	int choice();
	int getSum() const;
	void clear();
	bool checkSameCards() const;
private:
	string name;
	double balance;
	double bank;
	vector<Card> hand;
	
	int choiceSplit() const;
};

