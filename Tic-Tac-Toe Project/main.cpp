#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initialiseGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
//bool isBoardFull(string gameBoard[ROWS][COLS]);
//bool cellAlreadyOccupied(string gameBoard[ROWS][COLS]);

int main()
{
	runGame();

	return 0;
}

void runGame()
{
	string winner = "";
	string gameBoard[ROWS][COLS];
	initialiseGameBoard(gameBoard);
	printCurrentBoard(gameBoard);

}

void initialiseGameBoard(string gameBoard[ROWS][COLS])
{
	for (int row = 0; row < ROWS; row++) 
	{
		for (int col = 0; col < COLS; col++)
		{
			gameBoard[row][col] = " ";
		}
	}
}

void printCurrentBoard(string gameBoard[ROWS][COLS])
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			cout << gameBoard[row][col] << " |";	
	
		}
		
		cout << endl << endl;
	}
}

//bool isBoardFull(string gameBoard[ROWS][COLS])
//{}
//
//bool cellAlreadyOccupied(string gameBoard[ROWS][COLS])
//{}