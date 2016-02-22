#pragma once

/*
 * !IMPORTANT!
 * For simplicity, rows will be handled as rows until the playing field is drawn. 
 * Then the rows become columns for that time.
 */

#define MAX_FIELD_SIZE 8

enum EPlayerType
{
	NONE,
	P1,
	P2
};



class Field
{
	public:
		Field(char p1sym, char p2sym);
		bool set_field(int row, EPlayerType ptype);
		EPlayerType check_for_winning_conditions();
		void render();

	private:
		int** m_boxes; // 0 = empty, 1 = player1, 2 = player2
		char m_p1sym;
		char m_p2sym;

		EPlayerType linear_check(int origin_x, int origin_y, int offset_x, int offset_y);
		

};