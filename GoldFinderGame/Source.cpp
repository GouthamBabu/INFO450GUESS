#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;
const int boardSize = 8;
void printGameBoard(char gameBoard[boardSize][boardSize]);
int randspot();

int main()
{
	char startBoard[boardSize][boardSize]; //array to be displayed at the begining of the game.
	char gameBoard[boardSize][boardSize];
	int numgold, row, col;
	int play = 1;
	do
	{

		for (row = 0; row < 8; row++)//fills the boards with fillers
		{
			for (col = 0; col < 8; col++)
			{
				startBoard[row][col] = '?';
				gameBoard[row][col] = ' ';
			}
		}
		{
			int gold = 0;

			int x, y;
			while (gold < 5) //fills the board with 5 golds
			{
				x = randspot();
				y = randspot();
				if (gameBoard[x][y] != 'G') // makes sure the same spot dosent get covered twice
				{
					gameBoard[x][y] = 'G';
					gold++;
				}

			}
			x = randspot();
			y = randspot();
			if (gameBoard[x][y] == 'G') //makes sure to get new random number if the spot has gold so the bomb dosent cover a gold
			{
				x = randspot();
				y = randspot();
			}
			else
			{
				gameBoard[randspot()][randspot()] = 'B';
			}


		}

		printGameBoard(startBoard); //calls display with the begining board

		int xGuess, yGuess, numChances; // playing the game starts here
		int points = 0;

		cout << "*************************************************" << endl;
		cout << "**                 Find the gold!              **" << endl;
		cout << "**               you have 5 chances            **" << endl;
		cout << "**              Hit a bomb you loose           **" << endl;
		cout << "**  If you guess right you get an extra chance **" << endl;
		cout << "**                  GOOD LUCK!                 **" << endl;
		cout << "*************************************************" << endl;
		for (numChances = 5; numChances > 0; numChances--) //5 chances
		{
			cout << "enter x coordinate between 0 - 8:";
			cin >> xGuess; cout << endl;
			cout << "enter Y coordinate between 0 - 8:";
			cin >> yGuess; cout << endl;

			if (gameBoard[xGuess][yGuess] == 'G')
			{
				points++;
				cout << "you found gold! You now have" << points << " point(s). and 1 extra guess for finding gold! number of chances: " << numChances - 1 << endl;
				gameBoard[xGuess][yGuess] = 'F';
				numChances++; //rewards the player with extra guess for guessing correctly
			}
			else if (gameBoard[xGuess][yGuess] == 'B')
			{
				cout << "Looser! you hit a bomb." << endl;
				break;
			}
			else
				cout << "you missed. You have " << numChances - 1 << " chances left." << endl;
		}
		cout << "You finished the game with " << points << " point(s)" << endl << endl; //final points
		printGameBoard(gameBoard); // final board
		cout << "press 1 if you would like to play again" << endl; //replay option
		cin >> play;

	} while (play == 1);

	system("pause");
	return 0;
}


void printGameBoard(char gameBoard[boardSize][boardSize]) //printing the array
{
	int row, col;
	cout << "     0 |  1 | 2  | 3 |  4 |  5  |  6  |  7 |" << endl; //format
	cout << "  _________________________________________" << endl;// format

	for (row = 0; row < boardSize; row++)
	{
		cout << row << "|";
		for (col = 0; col < boardSize; col++)
		{
			cout << setw(4) << gameBoard[row][col] << "|";

		}

		cout << endl;
	}
}
int randspot() //function to generate random spots on the board
{
	int spot;
	static int nCalls = 0;

	if (nCalls == 0)
		srand(time(NULL));
	nCalls++;

	spot = (rand() % (boardSize));
	return spot;

}
