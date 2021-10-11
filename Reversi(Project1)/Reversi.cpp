//functions
#include "Reversi.h"

Reversi::Reversi()
{
	/*
	prints starting position of game, starting with 'b' turn
	*/

	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			board[i][j] = ' ';
	
	board[3][3] = 'w';
	board[3][4] = 'b';
	board[4][3] = 'b';
	board[4][4] = 'w';
	
	
	turn = 'b';


}

int Reversi::FindEmpty(const int ROW, const int COL, const int Direction, int& eRow, int& eCol)
{
	/*
	Direction: function searches for empty cells in all 8 directions surrounding cell inputed
	Pre-condition: COLS & ROWS contain loop in 8x8 dimension
	Post-condition: returns cells in board that contain no char
	*/

	if (Direction == NORTH)
	{
		for (int i = ROW - 1; i >= 0; i--)
		{
			if (board[i][COL] == ' ')
			{
				eRow = i;
				eCol = COL;
				return 1;  //found an an empty cell north of the given cell
			}
		}
	}
	else if (Direction == NE)
	{
		
		for (int j = COL - 1, i = ROW + 1; j >= 0 && i < ROWS; j--, i++)
		{
			if (board[i][j] == ' ')
			{
				eRow = i;
				eCol = j;
				return 1;  //found an an empty cell diagonally northeast of the given cell
			}
		}
	}

	if (Direction == EAST)
	{
		for (int i = COL + 1; i < COLS; i++)
		{
			if (board[ROW][i] == ' ')
			{
				eRow = ROW;
				eCol = i;
				return 1;  //found an an empty cell east of the given cell
			}
		}
	}
	if (Direction == WEST)
	{
		for (int i = COL - 1; i >= 0; i--)
		{
			if (board[ROW][i] == ' ')
			{
				eRow = ROW;
				eCol = i;
				return 1;  //found an an empty cell west of the given cell
			}
		}
	}
	else if (Direction == SE)
	{
		//for(int i=ROW+1; i<ROWS; i++)
		for (int j = COL + 1, i = ROW + 1; j < COLS && i < ROWS; j++, i++)
		{
			if (board[i][j] == ' ')
			{
				eRow = i;
				eCol = j;
				return 1;  //found an an empty cell on the right of the given cell
			}
		}
	}

	if (Direction == SOUTH)
	{
		for (int i = ROW + 1; i < ROWS; i++)
		{
			if (board[i][COL] == ' ')
			{
				eRow = i;
				eCol = COL;
				return 1;  //found an an empty cell going south of the given cell
			}
		}
	}
	else if (Direction == SW)
	{

		for (int j = COL + 1, i = ROW + 1; j < COLS && i < ROWS; j++, i++)
		{
			if (board[i][j] == ' ')
			{
				eRow = i;
				eCol = j;
				return 1;  //found an an empty cell on the south west of the given cell
			}
		}
	}
	else if (Direction == NW)
	{

		for (int j = COL - 1, i = ROW - 1; j >= 0 && i >= 0; j--, i--)
		{
			if (board[i][j] == ' ')
			{
				eRow = i;
				eCol = j;
				return 1;  //found an an empty cell on the right of the given cell
			}
		}
	}

	return 0;
}

int Reversi::FlipColor(int eRow, int eCol, char color)
{
	{
		/*
		Description: changes opponents color to current players color where possible
		Pre-condition: eRow and eCol are the coordinates of a qualifying cell for color(=x) 
		Post-condition: returns a change in opponents pieces that qualify to be flipped
		*/
		int rc;
		int TRow, TCol;
		if (FindCell(eRow, eCol, WEST, TRow, TCol) == 1)
		{
			for (int i = eCol - 1; board[eRow][i] == Opposite(color);i--)     // flip the colors
				board[eRow][i] = color;
		}
		if (FindCell(eRow, eCol, EAST, TRow, TCol) == 1)
		{
			for (int i = eCol + 1; board[eRow][i] == Opposite(color);i++)     // flip the colors
				board[eRow][i] = color;
		}
		if (FindCell(eRow, eCol, SOUTH, TRow, TCol) == 1)
		{
			for (int i = eRow + 1; board[i][eCol] == Opposite(color);i++)     // flip the colors
				board[i][eCol] = color;
		}
		if (FindCell(eRow, eCol, NORTH, TRow, TCol) == 1)
		{
			for (int i = eRow - 1; board[i][eCol] == Opposite(color);i--)     // flip the colors
				board[i][eCol] = color;
		}
		if (FindCell(eRow, eCol, SE, TRow, TCol) == 1)
		{
			for (int j = eCol + 1, i = eRow + 1; board[i][j] == Opposite(color);j++, i++)     // flip the colors
				board[i][j] = color;
		}
		if (FindCell(eRow, eCol, NW, TRow, TCol) == 1)
		{
			for (int j = eCol - 1, i = eRow - 1; board[i][j] == Opposite(color);j--, i--)     // flip the colors
				board[i][j] = color;
		}
		if (FindCell(eRow, eCol, NE, TRow, TCol) == 1)
		{
			for (int j = eCol + 1, i = eRow - 1; board[i][j] == Opposite(color);j++, i--)     // flip the colors
				board[i][j] = color;
		}
		if (FindCell(eRow, eCol, SW, TRow, TCol) == 1)
		{
			for (int j = eCol - 1, i = eRow - 1; board[i][j] == Opposite(color);j--, i++)     // flip the colors
				board[i][j] = color;
		}
		return 0;
	}
}


int Reversi::FindCell(const int ROW, const int COL, const int Direction, int& TRow, int& TCol)
{
	/*
	 Description: function checks through cells in all 8 directions 
	 Pre-condition: eRow and eCol are the coordinates of a qualifying cell for color(=x) 
	 Post-condition: returns 1 if a cell that needs color flipping is found, -1 if not
	*/
	if (Direction == WEST)
	{
		for (int i = COL - 1; i >= 0; i--)
		{
			if (board[ROW][i] == turn)
			{
				TRow = ROW;
				TCol = i;
				return 1;  //found a cell with the correct color
			}
		}
	}
	else if (Direction == EAST)
	{
		for (int i = COL + 1; i < COLS; i++)
		{
			if (board[ROW][i] == turn)
			{
				TRow = ROW;
				TCol = i;
				return 1; 
			}
		}
	}
	else if (Direction == SOUTH)
	{
		for (int i = ROW + 1; i < ROWS; i++)
		{
			if (board[i][COL] == turn)
			{
				TRow = i;
				TCol = COL;
				return 1; 
			}
		}
	}
	else if (Direction == NORTH)
	{
		for (int i = ROW - 1; i >= 0; i--)
		{
			if (board[i][COL] == turn)
			{
				TRow = i;
				TCol = COL;
				return 1;  
			}
		}
	}
	else if (Direction == SE)
	{
		for (int j = COL + 1, i = ROW + 1; j < COLS && i < ROWS; j++, i++)
		{
			if (board[i][j] == turn)
			{
				TRow = i;
				TCol = j;
				return 1;  
			}
		}
	}
	else if (Direction == NW)
	{
		for (int j = COL - 1, i = ROW - 1; j >= 0 && i >= 0; j--, i--)
		{
			if (board[i][j] == turn)
			{
				TRow = i;
				TCol = j;
				return 1;  
			}
		}
	}
	else if (Direction == SW)
	{
		for (int j = COL - 1, i = ROW + 1; j >= 0 && i < ROWS; j--, i++)
		{
			if (board[i][j] == turn)
			{
				TRow = i;
				TCol = j;
				return 1;  
			}
		}
	}
	else if (Direction == NE)
	{
		for (int j = COL + 1, i = ROW - 1; j < COLS && i >= 0; j++, i--)
		{
			if (board[i][j] == turn)
			{
				TRow = i;
				TCol = j;
				return 1; 
			}
		}
	}

	return -1;
}


int Reversi::count(char color)
{
	/*
	Description: function counts number of each color
	Pre-condition: count starts at 0
	Post-condition: returns number of each players piece
	*/
	int count = 0;

	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] == color)
				count++;

		}

	return count;
}

int Reversi::setDisk(int row, int col, char color)
{
	/*
	Description: sets pieces to a color
	Pre-condition: menu option selected for setting pieces on valid row&col
	Post-condition: return 0 if a valied move is chosen, otherwise return -1
	*/

	ClearX();
	MarkPossibleMoves(turn);

	bool xWasFound = false;
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] == 'x')
				xWasFound = true;
		}

	if (xWasFound == true)
	{
		if (board[row][col] == 'x')
		{
			board[row][col] = color;
			FlipColor(row, col, color);

			turn = Opposite(turn);
			ClearX();
			printBoard();
			return 0;
		}
		else
		{
			ClearX();
			cout << "The specified address (" << row << "," << col << ") is not a valid location" << endl;
			return -1;
		}
	}
	else
	{

		cout << "There is no move for '" << turn << " switching to the opposite color" << endl;
		turn = Opposite(turn);
		MarkPossibleMoves(turn);
		xWasFound = false;
		bool EmptyWasFound = false;
		for (int i = 0;i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
			{
				if (board[i][j] == 'x')
					xWasFound = true;
			}

		ClearX();
		for (int i = 0;i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
			{
				if (board[i][j] == ' ')
					xWasFound = true;
			}

		if (xWasFound == false && EmptyWasFound == false)
		{
			char Response;
			cout << "The game is over" << endl;
			cout << "Do you want to start a new game?  ";
			cin >> Response;
			if (toupper(Response) == 'Y')
				resetBoard();

		}
	}
}

//------------------------------------------------------------------------------
int Reversi::resultOfMove(int row, int col, char color)
{
	/*
	Description: function returns the number of tiles flipped from a given move
	Pre-condition: players moves have been chosen 
	Post-condition: returns count of colors on the board
	*/
	char boardTemp[ROWS][COLS];
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			boardTemp[i][j] = board[i][j];
	char OldTurn = turn;
	setDisk(row, col, color);
	turn = OldTurn;
	int cnt = count(color);
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			board[i][j] = boardTemp[i][j];

	return cnt;
}

//------------------------------------------------------------------------------
void Reversi::bestMove(int& row, int& col, int& flipped, char color)
{
	/*
	 Description: function calculates what move will generate the most amount of tiles flipped
	 Pre-condition: all possible entries must be 'flippable' tokens
	 Post-condition: coordinates of move will get reflected in row & col
	*/
	int maxFlipped = 0;
	int cnt;
	MarkPossibleMoves(color);
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			if (board[i][j] == 'x')
			{

				cnt = resultOfMove(i, j, color);
				if (cnt > maxFlipped)
				{
					row = i;
					col = j;
					maxFlipped = cnt;
				}
			}
	ClearX();
	printBoard();

}
//------------------------------------------------------------------------------

void Reversi::printBoard() //*
{
	/*
		Description:  prints board
		PreCondition:  board array is populated and ready for presentation to users.
		PostCondition: screen is cleared and the content of the board is displayed.

	*/
	int row = 0;
	int col = 0;
	char ColNum = '1';
	system("cls");



	cout << "   0    1   2   3   4   5   6   7  " << endl;
	cout << "  +---+---+---+---+---+---+---+---+" << endl;

	for (row = 0; row < ROWS; row++)
	{
		cout << row << " | ";
		for (int col = 0; col < COLS; col++)
		{
			cout << board[row][col] << " | ";
		}
		cout << endl;
		cout << "  +---+---+---+---+---+---+---+---+" << endl;

	}

	cout << "Menu:  1) Place a disk" << endl;
	cout << "       2) See movement rules" << endl;
	cout << "       3) Display possible moves" << endl;
	cout << "       4) Display best move" << endl;
	cout << "       5) Exit" << endl;

	if (turn == 'b')
		cout << "\tBlack's turn" << endl;
	else
		cout << "\tWhite's turn" << endl;


}

void Reversi::resetBoard()
{
	/*
	Description: board reset for end of game
	Pre-condition: players have a choice to replay the game or not
	Post-condition: if players decide to play again the board will clear and reset
		*/
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			board[i][j] = ' ';

	board[3][3] = 'w';
	board[3][4] = 'b';

	board[4][3] = 'b';
	board[4][4] = 'w';
	turn = 'b';
	printBoard();

}
// returns temporary x placement on board to show available moves
int Reversi::MarkPossibleMoves(char color)
{
	/*
	Description: prints 'x''s on board where possible move is located
	Pre-condition: empty cell locations have been calculated for possible moves for current player
	Post-condition: returns 'x' in cells that can have pieces placed at
	*/
	int eRow, eCol;  //location of EmptyRow and EmptyCol
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] == color)
			{
				if (FindEmpty(i, j, WEST, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, EAST, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, SOUTH, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, NORTH, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, SE, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, NW, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, NE, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
				if (FindEmpty(i, j, SW, eRow, eCol))
				{
					if (CorrectColor(i, j, eRow, eCol) == Opposite(color))
						board[eRow][eCol] = 'x';
				}
			}
		}


	return 0;
}

char Reversi::CorrectColor(const int i, const int j, const int eRow, const int eCol)
{

	/*
	Description: Determines the color between cells
	Pre-condition: checking for correct color to flip
	Post-condition:returns uniform color of current players pieces, otherwise return 0
	*/
	int Dx, Dy, d;
	char DistColor;

	if (abs(eRow - i) >= abs(eCol - j))
		d = abs(eRow - i);
	else
		d = abs(eCol - j);


	Dx = eCol - j;
	if (Dx < 0)
		Dx = -1;
	else if (Dx > 0)
		Dx = 1;

	Dy = eRow - i;
	if (Dy < 0)
		Dy = -1;
	else if (Dy > 0)
		Dy = 1;

	DistColor = board[i + Dy][j + Dx];
	if (d == 1)
		return DistColor;

	for (int k = 2; k < d; k++)
	{
		if (board[i + Dy * k][j + Dx * k] != DistColor)
			return 0;

	}
	return DistColor;
}

char Reversi::Opposite(char color)
{
	/*
	Description: switches colors
	Pre-condition: color is char
	Post-condition: returns opposite color
	*/
	if (color == 'b')
		return 'w';

	if (color == 'w')
		return 'b';
}

void Reversi::ClearX()
{
	/*
	Description: clears possible moves after move is made
	Pre-condition: possible moves are 'x' on board
	Post-condition: all x's change to ' '
	*/
	for (int i = 0;i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			if (board[i][j] == 'x')
				board[i][j] = ' ';
}

