#pragma once
#include<list>
#include<string>
#include<vector>
#include "Card.h"

using namespace std;

class Deck
{
private:
	vector<string> typeOfcard{ "C", "P", "T", "L" };
	vector<string> listOfCard{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "Q", "K", "A"};
	vector<Card*> deck{};
public:
	Deck(); 

	~Deck() {};

	vector<Card*> InitDeck();

	vector<Card *> DrawCard(vector<Card*> deck, vector<Card*> hand);

	vector<string> getTypeOfcard() {
		return typeOfcard;
	}
	
	vector<string> getListOfCard() {
		return listOfCard;
	}

	vector<Card*> getDeck() {
		return deck;
	}

	void setDeck(vector<Card*> aDeck) {
		deck = aDeck;
	}
};

