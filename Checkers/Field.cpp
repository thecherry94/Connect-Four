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
	}s

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

	int* sel_row = m_boxes[row];

	if (sel_row[0] != 0)
		return false;

	for (int x = 0; x < MAX_SIZE; x++)
	{
		if (sel_row[x] != 0)
		{
			sel_row[x - 1] = (int)ptype;
			return true;
		}
	}
}


void Field::render()
{
	for (int col = 0; col < MAX_SIZE; col++)
	{
		for (int row = MAX_SIZE - 1; row >= 0; row++)
		{
			cout << m_boxes[row][col];
		}
	}
}