#include "Game.h"

void Game::start()
{
	vector<Player> players;
	int count_players = 7;
	while (count_players > 6 || count_players < 1) {
		cout << "Enter count players: ";
		cin >> count_players;
	}
	for (int i = 0; i < count_players; i++) {
		string name;
		cout << "Enter name: ";
		cin >> name;
		int balance;
		cout << "Enter balance: ";
		cin >> balance;
		players.push_back(Player(name, balance));
	}
	while (!players.empty()) {
		Round round;
		for (int i = 0; i < count_players; i++) {
			round.AddPlayer(players[i]);
			round.CheckBalance();
		}
		round.start();
		round.ReturnResults(players);

		for (int i = 0; i < players.size(); i++)
			if (players[i].getBalance() < 25) {
				players.erase(players.begin() + i);
				i--;
				count_players--;
			}

		cout << "Who want exit enter name or 0 if none\n";
		string name = "";
		while (name != "0" && !players.empty()) {
			cout << "Enter name or 0: ";
			cin >> name;
			for (int i = 0; i < players.size(); i++) {
				if (players[i].getName() == name) {
					players.erase(players.begin() + i);
					count_players--;
					break;
				}
			}
		}
	}
	cout << "---End---" << endl;
}

void Game::menu()
{
	cout << "Black Jack" << endl;
	cout << "0 - Exit\n1 - Start game\n";
	srand(time(0));
	int choice = -1;
	while (choice != 0) {
		cout << "Menu|Enter variant: ";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Exit success!" << endl;
			break;
		case 1:
			start();
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
}
