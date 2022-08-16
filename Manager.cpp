#include "Manager.h"
#include "Deck.h"
#include "InitFrame.h"
#include <iostream>

using namespace std;

Manager::Manager() {
	Manager::setBank(500);
	Manager::setBet(0);
}

void Manager::start()
{
	InitFrame initframe;
	bool running = true;

	Deck deck; 
	deck.InitDeck();

	while (running)
	{
		if (!initframe.ProcessMessages()) {
			running = false;
		}

		Sleep(10);
	}
}
