//main source
//Maya Soleimani
//2/23/20
//Revision history
//Othello is a two-player game on a 8x8 board where each player
//tries to capture the most amount of their opponents pieces
//by trapping it between two of their own pieces. Black always
//goes first.
#include "Reversi.h"
#include <stdio.h>
#include <iostream>
#include <string>


void GetSelection(int& s);


int main()
{
	int menu = 0;
	Reversi R;
	/*
	R.setDisk(3, 3, 'b');
	R.setDisk(3, 4, 'w');
	R.setDisk(4, 3, 'w');
	R.setDisk(4, 4, 'b');
	*/
	R.printBoard();

	while (true) // menu loop
	{
		GetSelection(menu);
		if (menu == 1)     // place a disk in a square
		{
#pragma region Place a disk
			int RRow, RCol;
			cout << "State the row(0-7) and col(0-7) of the square where you want to place a disk:";
			cin >> RRow >> RCol;
			R.setDisk(RRow, RCol, R.CurrentColor());

			//#pragma end_region Place a disk
		}
		else if (menu == 2)   //Movement rules
		{
			cout << "Black always begins the game. Each piece played must be laid adjacent" << endl;
			cout << "to an opponent's piece so that the opponent's piece or a row of " << endl;
			cout << "opponent's pieces is flanked by the new piece and another piece of the" << endl;
			cout << "player's color. All of the opponent's pieces between these two pieces" << endl;
			cout << "are 'captured' and turned over to match the player's color. The game" << endl;
			cout << "ends when the board is completely covered or no more possible moves" << endl;
			cout << "are available. Player with most color pieces on the board wins." << endl;
		}
		else if (menu == 3)   //Display the possible moves
		{
			R.MarkPossibleMoves(R.CurrentColor());
			R.printBoard();
		}
		else if (menu == 4)   //Display best moves
		{
			int row, col, flipped;
			R.bestMove(row, col, flipped, R.CurrentColor());
			cout << "The best move for color '" << R.CurrentColor() << "' is (" << row << "," << col << ")" << endl;

		}
		else if (menu == 5)      //exit
			break;
	}
	return 0;
}

void GetSelection(int& s)
{
	/*
	recieves selection by user for action in game
	*/
	cin.clear();
	cout << "Selection: ";
	cin >> s;
}