#include <iostream>
#include "InitFrame.h"

int main() {
	InitFrame initframe;
	bool running = true;
	while (running)
	{
		if (!initframe.ProcessMessages()) {
			running = false;
		}

		Sleep(10);
	}

	return 0;
}