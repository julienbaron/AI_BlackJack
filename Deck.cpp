#include "Deck.h"
#include "Card.h"
#include "Manager.h"
#include <iostream>
#include <random>

using namespace std; 

Deck::Deck()
{
	Deck::setDeck(Deck::InitDeck());
}

vector<Card*> Deck::InitDeck()
{
	vector<Card*> bufferDeck{};
	int count = 0;
	for (string type : Deck::getTypeOfcard()) {
		for (string number : Deck::getListOfCard()) {
			string typeNumber = type + number;
			bufferDeck.push_back(new Card(typeNumber));
			count += 1;
		}
	}
	 auto rng = default_random_engine{};
	 shuffle(begin(bufferDeck), end(bufferDeck), rng);
	 return bufferDeck;
}

vector<Card*> Deck::DrawCard(vector<Card*> deck, vector<Card*> hand)
{
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(1, deck.size()); 
	unsigned int randomSelected = dist(rng);
	auto cardSelected = deck[randomSelected];
	deck.erase(deck.begin() + randomSelected);
	hand.push_back(cardSelected);
	for (Card* card : hand) {
		card->setNumberOfCard(1); 
	}
	return hand;
}




