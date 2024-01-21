#include "Player.h"

Player::Player(string name, double bank) : name(name), balance(bank), bank(0) {}

string Player::getName() const
{
	return name;
}

double Player::getBalance() const
{
	return balance;
}

void Player::setBalance(double balance)
{
	this->balance = balance;
}

double Player::getBank() const
{
	return bank;
}

void Player::setBank(double bank)
{
	this->bank = bank;
}

void Player::Hit(Deck& deck)
{
	if (deck.is_empty()) deck.init(6);
	if (deck.getCard().getValue().getRank() == 14 && getSum() + deck.getCard().getValue().getValue() > 21) deck.setCard(1);
	hand.push_back(deck.getCard().getValue());
}

void Player::Stand()
{
}

void Player::Split(Deck& deck, const Dealer dealer)
{
	int bank = this->bank;
	Card card(hand.back().getRank(), hand.back().getValue());
	hand.pop_back();
	for (int i = 0; i < 2; i++) {
		int choice = -1;
		while (choice != 2) {
			choice = choiceSplit();
			switch (choice) {
			case 1:
				Hit(deck);
				CheckHand();
				break;
			case 2:
				Stand();
				CheckHand();
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
			}
			if (getSum() >= 21) break;
		}
		if (dealer.getSum() > 21) {
			if (getSum() < 21) {
				setBalance(getBalance() + getBank() * 2);
				setBank(0);
			}
			else if (getSum() == 21) {
				setBalance(getBalance() + getBank() * 3);
				setBank(0);
			}
			else {
				setBalance(getBalance() + getBank());
				setBank(0);
			}
		}
		else if (dealer.getSum() == 21) {
			if (getSum() == 21) {
				setBalance(getBalance() + getBank());
				setBank(0);
			}
			else
				setBank(0);
		}
		else {
			if (getSum() > dealer.getSum() && getSum() < 21) {
				setBalance(getBalance() + getBank() * 2);
				setBank(0);
			}
			else if (getSum() == 21) {
				setBalance(getBalance() + getBank() * 3);
				setBank(0);
			}
			else if (getSum() == dealer.getSum()) {
				setBalance(getBalance() + getBank());
				setBank(0);
			}
			else
				setBank(0);
		}
		if (i == 0) {
			this->bank += bank;
			balance -= bank;
			hand.clear();
			hand.push_back(card);
		}
	}
	hand.clear();
}
void Player::Double(Deck& deck)
{
	if (getBalance() < getBank()) return;
	setBalance(getBalance() - getBank());
	setBank(getBank() * 2);
	Hit(deck);
}

void Player::Surrender()
{
	setBalance(getBalance() + getBank() / 2);
	setBank(0);
	hand.clear();
}

void Player::CheckHand() const
{
	cout << "Cards: ";
	for (int i = 0; i < hand.size(); i++) {
		hand[i].printRank();
	}
	cout << endl;
}

int Player::choice()
{
	int choice;
	cout << "1 - Hit\n2 - Stand\n3 - double\n4 - split\n5 - surrender\n";
	cout << "Enter variant: ";
	cin >> choice;
	return choice;
}

int Player::getSum() const
{
	int sum = 0;
	for (int i = 0; i < hand.size(); i++)
		sum += hand[i].getValue();
	return sum;
}

void Player::clear()
{
	hand.clear();
}

bool Player::checkSameCards() const
{
	return hand[0].getRank() == hand[1].getRank();
}

int Player::choiceSplit() const
{
	int choice;
	cout << "1 - Hit\n2 - Stand\n";
	cout << "Enter variant: ";
	cin >> choice;
	return choice;
}
