#pragma once
#include "Card.h"
#include "Deck.h"

/*struct Chip
{
	enum ChipStandart : int { CHIP_1 = 1, CHIP_2 = 5, CHIP_3 = 20, CHIP_4 = 50 };
	std::string code;
	int value;
	std::string bitmap;

	Chip();

	Chip(std::string aCode, int aValue, std::string aBitmap);
};*/


class Manager
{
private:
	unsigned int bank;
	unsigned int bet = 0 ;
	int refund;
	vector<Card*> deckPlayer{};
	vector<Card*> deckCroup{};

	

public: 
	Manager();

	void start();

	vector<Card*> getDeckPlayer() {
		return deckPlayer;
	}

	vector<Card*> getDeckCroup() {
		return deckCroup; 
	}


	int getBet() {
		return bet;
	}

	void setBank(int refund) {
		bank += refund;
	}

	void setBet(int aBet) {
		bet = aBet;
	}

	void setDeckPlayer(vector<Card*> aHandP) {
		deckPlayer = aHandP; 
	}

	void setDeckCroup(vector<Card*> aHandC) {
		deckCroup = aHandC; 
	}
	
};

