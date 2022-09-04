#pragma once
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "InitFrame.h"
#include <memory>

struct Chip 
{
public :
	enum ChipStandart : int { CHIP_1 = 1, CHIP_2 = 5, CHIP_3 = 20, CHIP_4 = 50 };
	vector<std::string> bitmapVector{ "chip_1.bmp","chip_2.bmp","chip_3.bmp","chip_4.bmp" };
	std::string code;
	int value;
	std::string bitmap;

	Chip() :code("Unknown"), value(0), bitmap("Unknown") {}

	~Chip() {
		std::cout << "ahh";
	};

	Chip(std::string aCode, int aValue, std::string aBitmap) {
		code = aCode;
		value = aValue;
		bitmap = aBitmap;
	}

	std:: vector<std::string> getBitmapVetcor()  {
		return bitmapVector;
	}

	void setBitmapVector(int lenCut) {
		bitmapVector.resize(bitmapVector.size() - lenCut);
	}

};


class Manager
{
private:
	unsigned int bank;
	unsigned int bet = 0 ;
	int refund;
	vector<Card*> deckPlayer{};
	vector<Card*> deckCroup{};
	std::vector<Chip*> chipCount{};
	std::vector<std::string> chipPaint;

public: 
	Manager();

	~Manager(){}

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

	std::vector<Chip*> getChipCount() {
		return chipCount;
	}

	int getBank() {
		return bank; 
	}

	void setBank(int refund) {
		bank += refund;
	}

	void setChipPaint(vector<std::string> aChipPaint) {
		chipPaint = aChipPaint;
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

	void setChipCount(vector<Chip*> aChipCount) {
		chipCount = aChipCount;
	}

	vector<Chip*> InitChipBet(int bet);

	void InitChipPaint(InitFrame initframe);
};

