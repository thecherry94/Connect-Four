#include "Game.hpp"
#include "MainMenu.hpp"

#include <iostream>
#include <Windows.h>

using namespace std;

void Game::start()
{
	MainMenu menu;

	while (true)
	{
		EMenuDecision dec;
		dec = menu.start();

		if (dec == EMenuDecision::GAME_START)
		{
			EPlayerType winner = EPlayerType::NONE;

			mp_field = new Field('1', '2');
			while(true)
			{ 
				system("CLS");
				mp_field->render();

				int choice = 0;

				cout << "Player 1: ";
				cin >> choice;

				mp_field->set_field(choice - 1, EPlayerType::P1);
				system("CLS");
				mp_field->render();
				winner = mp_field->check_for_winning_conditions();

				if (winner != EPlayerType::NONE)
					break;

				cout << "Player 2: ";
				cin >> choice;

				mp_field->set_field(choice - 1, EPlayerType::P2);
				system("CLS");
				mp_field->render();
				winner = mp_field->check_for_winning_conditions();

				if (winner != EPlayerType::NONE)
					break;
			}

			system("CLS");
			cout << winner << " has won!" << endl;
			system("PAUSE");
		}
	}
}