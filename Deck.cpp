#include "Deck.h"
#include "Card.h"
#include <iostream>

using namespace std; 

void Deck::InitDeck()
{
	for (string type : Deck::getTypeOfcard()) {
		for (string number : Deck::getListOfCard()) {
			string typeNumber = type + number;
			Deck::setDeck(Card::Card(typeNumber));
		}
	}
}
