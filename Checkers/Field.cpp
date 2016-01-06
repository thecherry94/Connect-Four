#include "Field.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Field::Field(char p1sym, char p2sym)
{
	m_boxes = new int*[MAX_SIZE];
	for (int y = 0; y < MAX_SIZE; y++)
	{
		m_boxes[y] = new int[MAX_SIZE];

		for (int x = 0; x < MAX_SIZE; x++)
			m_boxes[y][x] = 0;
	}

	m_p1sym = p1sym;
	m_p2sym = p2sym;
}

/*
 * Returns false if row completely occupied
 */
bool Field::set_field(int row, EPlayerType ptype)
{
	/*
	 * Since the array will be flipped by 90 degrees during rendering,
	 * the row selection has to be inverted.
	 * Meaning: The first element will be the last and so on
	 */
	row = abs(row - (MAX_SIZE - 1));

	if (m_boxes[row][0] != 0)
		return false;

	for (int x = 0; x < MAX_SIZE; x++)
	{
		if (m_boxes[row][x] == 0 && x == (MAX_SIZE - 1))
		{
			m_boxes[row][x] = (int)ptype;
			return true;
		}

		if (m_boxes[row][x] != 0)
		{			
			m_boxes[row][x - 1] = (int)ptype;
			return true;
		}
	}
}


void Field::render()
{
	cout << endl;

	for (int col = 0; col < MAX_SIZE; col++)
	{
		cout << "                                ";

		for (int row = (MAX_SIZE - 1); row >= 0; row--)
		{
			cout << m_boxes[row][col];

			if (row != 0)
				cout << " | ";
		}
		
		cout << endl;

		if (col != (MAX_SIZE - 1))
		{
			cout << "                               ";
			for (int row = (MAX_SIZE - 1); row >= 0; row--)
			{
				cout << "---";

				if (row != 0)
					cout << "+";
			}
		}

		cout << endl;
	}
}