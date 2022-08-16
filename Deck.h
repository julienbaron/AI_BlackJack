#pragma once
#include<list>
#include<string>
#include "Card.h"

using namespace std;

class Deck
{
private:
	list<string> typeOfcard{ "C", "P", "T", "L" };
	list<string> listOfCard{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "Q", "K", "A"};
	list<Card> deck{};
public:
	void InitDeck();

	list<string> getTypeOfcard() {
		return typeOfcard;
	}
	
	list<string> getListOfCard() {
		return listOfCard;
	}

	list<Card> getDeck() {
		return deck;
	}

	void setDeck(Card card) {
		deck.push_back(card);
	}
};

