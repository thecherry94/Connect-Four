#include <iostream>
#include "Field.hpp"
#include <Windows.h>

using namespace std;

int main()
{
	Field f('x', 'o');

	f.set_field(0, EPlayerType::P1);
	f.set_field(0, EPlayerType::P1);
	f.set_field(0, EPlayerType::P2);
	f.set_field(0, EPlayerType::P2);
	f.set_field(0, EPlayerType::P2);
	f.set_field(0, EPlayerType::P1);
	f.set_field(0, EPlayerType::P2);

	f.set_field(1, EPlayerType::P2);
	f.set_field(1, EPlayerType::P1);
	f.set_field(1, EPlayerType::P2);

	f.render();

	system("PAUSE");

	return 0;
}