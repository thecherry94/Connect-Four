#pragma once

/*
 * !IMPORTANT!
 * For simplicity, rows will be handled as rows until the playing field is drawn. 
 * Then the rows become columns for that time.
 */

#define MAX_SIZE 8

enum EPlayerType
{
	P1 = 1,
	P2
};

class Field
{
	public:
		Field(char p1sym, char p2sym);
		bool set_field(int row, EPlayerType ptype);
		int check_for_winning_conditions();
		void render();

	private:
		int** m_boxes; // 0 = empty, 1 = player1, 2 = player2
		char m_p1sym;
		char m_p2sym;

};