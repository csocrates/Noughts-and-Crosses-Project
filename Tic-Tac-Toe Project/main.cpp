#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initialiseGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
//bool isBoardFull(string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int a, int b, string gameBoard[ROWS][COLS]);
string checkWinner(string gameBoard[ROWS][COLS]);

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
	bool xTurn = true;
	while (winner == "")
	{	
		if (xTurn)
		{
			cout <<"X, it's your turn." <<endl;
		}
		else
		{
			cout <<"O, it's your turn."<< endl;
		}
		getUserInput(xTurn, gameBoard);
		xTurn = !xTurn;
		printCurrentBoard(gameBoard);
		winner = checkWinner(gameBoard);
	}
	cout << "Congratulations " << winner << "! You are the winner.";
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
			cout << gameBoard[row][col];
			if (col < 2)
			{
				cout <<	" | ";
			}
	
		}
		cout << endl;
		if (row < 2)
		{
			cout << "- - - - -" << endl;
		}
	}
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{	
	int a;
	int b;
	bool isInvalid = true;
	while (isInvalid)
	{

		cout << "Please enter the position you'd like to mark" << endl;
		cout << "(ROW then COLUMN, for each either 0, 1 or 2, seperated by a space)" << endl;
		cin >> a >> b;
		if (a < 0 || a > 2 || b < 0 || b > 2)
		{
			cout << "Sorry, row and column numbers must be within the limits." << endl;
		}
		if (a >= 0 && a <= 2 && b >= 0 && b <= 2)
		{
			if (cellAlreadyOccupied(a, b, gameBoard))
			{
				cout << "Sorry, that space is already taken!" << endl;
			}
			else 
			{
				isInvalid = false;
			}
		}
	}
	//outside validation here
	xTurn ? gameBoard[a][b] = "X" : gameBoard[a][b] = "O";

}

bool cellAlreadyOccupied(int a, int b, string gameBoard[ROWS][COLS])
{
	return gameBoard[a][b] == " " ? false : true;
}

string checkWinner(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		if(gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
		{
			return gameBoard[i][0];
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[0][i] && gameBoard[0][] == gameBoard[0][i])
		{
			return gameBoard[0][i];
		}
	}

};

//bool IsBoardFull(string gameBoard[ROWS][COLS])
//{}
//
