#include "MainMenu.hpp"

#include <iostream>

using namespace std;


MainMenu::MainMenu()
{
	
}

EMenuDecision MainMenu::start()
{
	cout << "(1) Start game" << endl;
	cout << "(2) Quit" << endl;

	int selection = 0;
	while (true)
	{
		cout << "Select a choice: ";
		cin >> selection;

		if (selection > 0 && selection < 3)
			break;
	}

	return static_cast<EMenuDecision>(selection);
}