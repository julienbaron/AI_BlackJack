#include "Manager.h"
#include "Deck.h"
#include "InitFrame.h"
#include <iostream>

using namespace std;

Manager::Manager() {
	Manager::setBank(500);
	Manager::setBet(15);
}

struct Chip {
	enum ChipStandart : int { CHIP_1 = 1, CHIP_2 = 5, CHIP_3 = 20, CHIP_4 = 50 };
	std::string code;
	int value;
	std::string bitmap;
	vector<Chip*> chipCount{};

	Chip() {}

	Chip(std::string aCode, int aValue, std::string aBitmap) {
		code = aCode;
		value = aValue;
		bitmap = aBitmap;
	}

	void setChipCount() {

	}
};

void Manager::start()
{
	InitFrame initframe;
	bool running = true;
	Deck deck; 
	while (running)
	{
		if (!initframe.ProcessMessages()) {
			running = false;
		}
		cout << Manager::getDeckCroup().size();

		

		/*for (int i = Manager::getDeckCroup().size(); i < 2; i++) {
			Manager::setDeckCroup(deck.DrawCard(deck.getDeck(), Manager::getDeckCroup()));
			auto card = Manager::getDeckCroup().back();
			Card* test = new Card("test");
			PostMessage(initframe.getWind(), WM_PAINT, 0, (LPARAM)test);
		}*/
		Sleep(30);
	}
}

vector<Chip*> InitChip(int bet)
{
	Chip chip;
	vector<Chip*> buffer{};
	while (bet != 0) {
		if (bet >= chip.CHIP_1) {
			Chip* chips = new Chip("chip_1.bmp", chip.CHIP_1, "chip_1.bmp");
			chip.
		}
		else if (bet >= chip.CHIP_2) {

		}
	}
	return vector<Chip*>();
}




