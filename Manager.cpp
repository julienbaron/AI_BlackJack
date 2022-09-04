#include "Manager.h"
#include "Deck.h"
#include "InitFrame.h"
#include <iostream>
#include <memory>

using namespace std;


Manager::Manager() {
	Manager::setBank(10);
	Manager::setBet(15);
}

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
		
		Manager::InitChipPaint(initframe);
		
		/*Manager::setChipCount(Manager::InitChip(Manager::getBet())); 

		for (Chip* a : Manager::getChipCount()) {
			std::cout << a->code;
		}*/

		/*for (int i = Manager::getDeckCroup().size(); i < 2; i++) {
			Manager::setDeckCroup(deck.DrawCard(deck.getDeck(), Manager::getDeckCroup()));
			auto card = Manager::getDeckCroup().back();
			Card* test = new Card("test");
			PostMessage(initframe.getWind(), WM_PAINT, 0, (LPARAM)test);
		}*/
		Sleep(30);
	}
}

void Manager::InitChipPaint(InitFrame initframe) {

	std::unique_ptr<Chip> listBitmap = std::make_unique<Chip>();

	bool msgSend = false;

	if (Manager::getBank() >= listBitmap->CHIP_4 && !msgSend) {
		PostMessage(initframe.getWind(), WM_PAINT, (WPARAM)0, (LPARAM)&listBitmap);
		msgSend = true;
	}
	else if (Manager::getBank() >= listBitmap->CHIP_3 && !msgSend) {
		listBitmap->setBitmapVector(1);
		SendMessage(initframe.getWind(), WM_PAINT, (WPARAM)0, (LPARAM)&listBitmap);
		msgSend = true;
	}
	else if (Manager::getBank() >= listBitmap->CHIP_2 && !msgSend) {
		listBitmap->setBitmapVector(2);
		SendMessage(initframe.getWind(), WM_PAINT, (WPARAM)0, (LPARAM)&listBitmap);
		msgSend = true;
	}
	else if(Manager::getBank() >= listBitmap->CHIP_1 && !msgSend) {
		listBitmap->setBitmapVector(3);
		SendMessage(initframe.getWind(), WM_PAINT, (WPARAM)0, (LPARAM)&listBitmap);
		msgSend = true;
	}
	else {
		listBitmap->setBitmapVector(4);
		std::cout << "ok";
		SendMessage(initframe.getWind(), WM_PAINT, (WPARAM)0, reinterpret_cast<LPARAM>(&listBitmap));
		msgSend = true; 
	}

	std::cout<< "ihh";
}

vector<Chip *> Manager::InitChipBet(int bet)
{
	Chip chip; 

	vector<Chip*> buffer;

	while (Manager::getBet() != 0) {

		if (Manager::getBet() >= chip.CHIP_4) {
			buffer.push_back(new Chip("chip_4.bmp", chip.CHIP_4, "chip_4.bmp"));
			bet -= chip.CHIP_4;
		}
		else if (Manager::getBet() >= chip.CHIP_3) {
			buffer.push_back(new Chip("chip_3.bmp", chip.CHIP_3, "chip_3.bmp"));
			bet -= chip.CHIP_3;
		}
		else if (Manager::getBet() >= chip.CHIP_2) {
			buffer.push_back(new Chip("chip_2.bmp", chip.CHIP_2, "chip_2.bmp"));
			bet -= chip.CHIP_2;
		}
		else if (Manager::getBet() >= chip.CHIP_1) {
			buffer.push_back(new Chip("chip_1.bmp", chip.CHIP_1, "chip_1.bmp"));
			bet -= chip.CHIP_2;
		}
	}
	return buffer;
}
