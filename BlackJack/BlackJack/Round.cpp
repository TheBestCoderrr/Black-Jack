#include "Round.h"

void Round::AddPlayer(Player p)
{
	players.push_back(p);
}

void Round::printPlayers() const
{
	for (int i = 0; i < players.size(); i++) 
		cout << "Player: " << players[i].getName() << " | balance: " << players[i].getBalance() << endl;
}

void Round::start()
{
	cout << "round start!" << endl;
	Deck deck(6);
	AddBank();
	for (int i = 0; i < players.size(); i++) {
		players[i].Hit(deck);
		players[i].Hit(deck);
		cout << players[i].getName() << " | ";
		players[i].CheckHand();
	}
	dealer.Hit(deck);
	dealer.Hit(deck);
	cout << "Dealer second card: ";
	dealer.getHand().front().printRank();
	cout << endl;
	while (dealer.getSum() <= 17) {
		dealer.Hit(deck);
	}
	vector<int> surrender_players;
	for (int i = 0; i < players.size(); i++) {
		cout << "Player: " << players[i].getName() << endl;
		int choice = -1;
		while (choice < 2 || choice > 5) {
			choice = players[i].choice();
			switch (choice) {
			case 1: 
				players[i].Hit(deck);
				players[i].CheckHand();
				break;
			case 2: 
				players[i].Stand();
				break;
			case 3:
				players[i].Double(deck);
				break;
			case 4:
				if(players[i].checkSameCards() && players[i].getBalance() >= players[i].getBank())
					players[i].Split(deck, dealer);
				else cout << "Split failed!" << endl;
				break;
			case 5:
				players[i].Surrender();
				surrender_players.push_back(i);
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
			}
			if (players[i].getSum() >= 21) break;
		}
	}
	cout << endl;
	for (int i = 0; i < players.size(); i++) {
		cout << "Player: " << players[i].getName() << " | ";
		players[i].CheckHand();
	}
	cout << "Dealer | ";
	dealer.CheckHand();
	CheckResults();

	dealer.clear();
	for (int i = 0; i < players.size(); i++)
		players[i].clear();
	cout << endl;
	printPlayers();
}

void Round::CheckBalance()
{
	for (int i = 0; i < players.size(); i++)
		if(players[i].getBalance() < 25) players.erase(players.begin() + i);
}

void Round::AddBank()
{
	int bank;
	for (int i = 0; i < players.size(); i++) {
		while (true) {
			cout << players[i].getName() << " | Enter bank: ";
			cin >> bank;
			if (bank >= 25 && bank <= 500 && bank <= players[i].getBalance()) break;
			else cout << "Incorrect value!" << endl;
		}
		players[i].setBank(bank);
		players[i].setBalance(players[i].getBalance() - bank);
	}
}

void Round::CheckResults()
{
	for (int i = 0; i < players.size(); i++)
		CheckResult(players[i]);
}

void Round::CheckResult(Player& player)
{
	if (dealer.getSum() > 21) {
		if (player.getSum() == 0) return;
		if (player.getSum() < 21) {
			player.setBalance(player.getBalance() + player.getBank() * 2);
			player.setBank(0);
		}
		else if (player.getSum() == 21) {
			player.setBalance(player.getBalance() + player.getBank() * 3);
			player.setBank(0);
		}
		else {
			player.setBalance(player.getBalance() + player.getBank());
			player.setBank(0);
		}
	}
	else if (dealer.getSum() == 21) {
		if (player.getSum() == 0) return;
		if (player.getSum() == 21) {
			player.setBalance(player.getBalance() + player.getBank());
			player.setBank(0);
		}
		else
			player.setBank(0);
	}
	else {
		if (player.getSum() == 0) return;
		if (player.getSum() > dealer.getSum() && player.getSum() < 21) {
			player.setBalance(player.getBalance() + player.getBank() * 2);
			player.setBank(0);
		}
		else if (player.getSum() == 21) {
			player.setBalance(player.getBalance() + player.getBank() * 3);
			player.setBank(0);
		}
		else if (player.getSum() == dealer.getSum()) {
			player.setBalance(player.getBalance() + player.getBank());
			player.setBank(0);
		}
		else
			player.setBank(0);
	}
}

void Round::ReturnResults(vector<Player>& p)
{
	swap(players, p);
}
