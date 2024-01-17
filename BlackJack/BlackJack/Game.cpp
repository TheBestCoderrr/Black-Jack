#include <iostream>
#include "Round.h"
using namespace std;

void Game() {
	vector<Player> players;
	int count_players;
	cout << "Enter count players: ";
	cin >> count_players;
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

		cout << "Who want exit enter name or 0\n";
		string name;
		bool succes = 0;
		while (!succes) {
			cout << "Enter name or 0: ";
			cin >> name;
			if (name == "0") {
				succes = 1;
				continue;
			}
			for (int i = 0; i < players.size(); i++) {
				if (players[i].getName() == name) {
					players.erase(players.begin() + i);
					succes = 1;
					count_players--;
					break;
				}
			}
		}
	}
	cout << "+End+" << endl;
}

int main() {
	cout << "Black Jack" << endl;
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
			Game();
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
}