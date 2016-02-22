#include <iostream>
#include "Field.hpp"
#include <Windows.h>

using namespace std;

int main()
{
	Field f('x', 'o');

	
	f.set_field(0, EPlayerType::P1);
	f.set_field(1, EPlayerType::P1);
	f.set_field(2, EPlayerType::P1);
	f.set_field(3, EPlayerType::P1);
	

	/*
	f.set_field(7, EPlayerType::P1);
	f.set_field(7, EPlayerType::P1);

	f.set_field(6, EPlayerType::P2);
	f.set_field(6, EPlayerType::P2);
	f.set_field(6, EPlayerType::P1);

	f.set_field(5, EPlayerType::P1);
	f.set_field(5, EPlayerType::P2);
	f.set_field(5, EPlayerType::P2);
	f.set_field(5, EPlayerType::P1);

	f.set_field(4, EPlayerType::P1);
	f.set_field(4, EPlayerType::P2);
	f.set_field(4, EPlayerType::P2);
	f.set_field(4, EPlayerType::P2);
	f.set_field(4, EPlayerType::P1);
	*/

	f.render();

	EPlayerType winner = f.check_for_winning_conditions2();

	if (winner != EPlayerType::NONE)
	{
		cout << winner << " has won!";
	}

	system("PAUSE");

	return 0;
}