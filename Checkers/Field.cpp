#include "Field.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Field::Field(char p1sym, char p2sym)
{
	m_boxes = new int*[MAX_FIELD_SIZE];
	for (int y = 0; y < MAX_FIELD_SIZE; y++)
	{
		m_boxes[y] = new int[MAX_FIELD_SIZE];

		for (int x = 0; x < MAX_FIELD_SIZE; x++)
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
	 * the row selection has to be horizontally mirrored at the center.
	 * Meaning: The first element will be the last and so on
	 */
	row = abs(row - (MAX_FIELD_SIZE - 1));

	if (m_boxes[row][0] != 0)
		return false;

	for (int x = 0; x < MAX_FIELD_SIZE; x++)
	{
		if (m_boxes[row][x] == 0 && x == (MAX_FIELD_SIZE - 1))
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

	return false;
}


/*
 * Checks the whole field horizontally, vertically and diagonally in order to find a winner
 */
EPlayerType Field::check_for_winning_conditions()
{
	/*
	 * Check horizontally
	 */
	for (int row = 0; row < MAX_FIELD_SIZE; row++)
	{
		for (int col = 0; col < MAX_FIELD_SIZE; col++)
		{
			if (m_boxes[row][col] != 0)
			{
				int p = m_boxes[row][col];

				if (col < (MAX_FIELD_SIZE - 3))
				{
					// If counter hits 3, a winner has been found
					int counter = 0;

					for (int i = 1; i <= 3; i++)	// TODO: Get better variable namer for i
					{
						if (m_boxes[row][col + i] == p)
							counter++;
					}

					// winner found
					if(counter == 3)
						return static_cast<EPlayerType>(p);
				}
			}
		}
	}

check2:

	/*
	 * Check vertically
	 * Basically the same as the code above
	 */
	for (int col = 0; col < MAX_FIELD_SIZE; col++)
	{
		for (int row = 0; row < MAX_FIELD_SIZE; row++)
		{
			if (m_boxes[row][col] != 0)
			{
				int p = m_boxes[row][col];

				if (row < (MAX_FIELD_SIZE - 3))
				{
					int counter = 0;

					for (int i = row; i < (MAX_FIELD_SIZE - 1); i++)
					{
						if (m_boxes[col][i] == p)
							counter++;
					}

					// winner found
					if(counter == 3)
						return static_cast<EPlayerType>(p);
				}
			}
		}
	}

check3:

	/*
	 * Check diagonally in the one direction
	 */
	for (int row = 0; row < MAX_FIELD_SIZE; row++)
	{

	}

	return EPlayerType::NONE;
}

void Field::render()
{
	cout << endl;

	for (int col = 0; col < MAX_FIELD_SIZE; col++)
	{
		cout << "                                ";

		for (int row = (MAX_FIELD_SIZE - 1); row >= 0; row--)
		{
			if (m_boxes[row][col] == 1)
				cout << m_p1sym;
			else if (m_boxes[row][col] == 2)
				cout << m_p2sym;
			else
				cout << " ";

			if (row != 0)
				cout << " | ";
		}
		
		cout << endl;

		if (col != (MAX_FIELD_SIZE - 1))
		{
			cout << "                               ";
			for (int row = (MAX_FIELD_SIZE - 1); row >= 0; row--)
			{
				cout << "---";

				if (row != 0)
					cout << "+";
			}
		}

		cout << endl;
	}
}