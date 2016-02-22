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
	 * Since the array will be rotated by 90 degrees during rendering,
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

EPlayerType Field::check_for_winning_conditions()
{
	EPlayerType type = EPlayerType::NONE;

	for (int col = 0; col < MAX_FIELD_SIZE; col++)
	{
		for (int row = 0; row < MAX_FIELD_SIZE; row++)
		{	
			type = linear_check(row, col, 1, 1);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, 1, 0);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, 1, -1);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, 0, -1);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, -1, -1);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, -1, 0);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, -1, 1);
			if (type != EPlayerType::NONE)
				return type;

			type = linear_check(row, col, 0, 1);
			if (type != EPlayerType::NONE)
				return type;
		}
	}

	return EPlayerType::NONE;
}

EPlayerType Field::linear_check(int origin_x, int origin_y, int offset_x, int offset_y)
{
	int p = m_boxes[origin_y][origin_x];
	int counter = 0;

	if (origin_x < 3 && offset_x < 0)
		return EPlayerType::NONE;
	if (origin_x > 3 && offset_x > 0)
		return EPlayerType::NONE;

	if (origin_y < 3 && offset_y < 0)
		return EPlayerType::NONE;
	if (origin_y > 3 && offset_y > 0)
		return EPlayerType::NONE;

	for (int i = 1; i <= 3; i++)
	{
		if (m_boxes[origin_y + offset_y*i][origin_x + offset_y*i] == p)
		{
			counter++;

			// Winner found!
			if (counter == 3)
			{
				return static_cast<EPlayerType>(p);
			}
		}
	}

	return EPlayerType::NONE;
}