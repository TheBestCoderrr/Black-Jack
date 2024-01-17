#pragma once
#include "Dealer.h"
#include "Player.h"
class Round
{
public:
	void AddPlayer(Player p);
	void printPlayers() const;
	void start();
	void CheckBalance();
	void AddBank();
	void ReturnResults(vector<Player>& p);
private:
	Dealer dealer;
	vector<Player> players;

	void CheckResults();
	void CheckResult(Player& player);
};

