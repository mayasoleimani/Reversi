#pragma once
//Header file for class
#include <iostream>
#include <stdio.h>
#define NORTH 0
#define NE 1
#define EAST 2
#define SE 3
#define SOUTH 4
#define SW 5
#define WEST 6
#define NW  7
using namespace std;

class Reversi
{
private:
	const static int ROWS = 8;
	const static int COLS = 8;
	char board[ROWS][COLS]; // each square holds 'b', 'w', or ' '
	char turn;              // keeps track of whoes turn it is
	int FindEmpty(const int ROW, const int COL, const int Direction, int& eRow, int& eCol);
	int FlipColor(int eRow, int eCol, char color);
	int FindCell(const int ROW, const int COL, const int Direction, int& TRow, int& TCol);


public:
	Reversi(); //initializes the board to all blanks
	int count(char color); // returns the number of squares containing color
	int setDisk(int row, int col, char color); // sets the square at (row, col) to color

	// returns the number of color - number of other color when a disk of color is placed at (row, col)
	int resultOfMove(int row, int col, char color);
	// returns the max resultOfMove(row,col) when a disk of color is placed at (row, col) by
	// returning the row and col by reference
	void bestMove(int& row, int& col, int& fliped, char color);
	void printBoard(); //prints the board to the console screen
	void resetBoard(); //resets game to starting positions
	int MarkPossibleMoves(char color);
	char CorrectColor(const int i, const int j, const int eRow, const int eCol);
	char Opposite(char color);
	void ClearX();  //Clears all the X
	char CurrentColor() { return turn; }



};