#pragma once
#include <iostream>
using namespace std;
class Card
{
public:
	Card(int rank, int value);
	int getRank() const;
	void setValue(int v);
	int getValue() const;
	void printRank() const;
private:
	int rank;
	int value;
};

