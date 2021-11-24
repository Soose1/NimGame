#include <iostream>
#include <ctime>
#include "Nim.h"

using namespace std;

void choose()
{
	int choose;
	Nim game;
	do
	{
		game.printmenu();
		cin >> choose;
		switch (choose)
		{
		case 1: game.twoplayers();
			break;
		case 2: game.ai();
			break;
		case 3: game.files();
			break;
		case 666:
			break;
		default: cout << "Неверно выбран режим игры, попробуйте еще раз!" << endl;
			break;
		}
	} while (choose != 666);
}

int main()
{
    setlocale(0, "");
    srand(time(0));
	choose();
    return 0;
}