#include <iostream>
#include <string>

using namespace std;
void printBoard(const char board[3][3])
{
	//print board
	cout << "   |   |   " << endl;
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << "   |   |   " << endl;
}

char checkWinner(const char board[3][3])
{
	char winner = ' ';
	//check winner

// rows - horizontal
	for (int r = 0; r < 3; r++){
		if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
			winner = board[r][0];
			break;
		}
	}

	// columns - vertical
	for (int c = 0; c < 3; c++){
		if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
			winner = board[0][c];
			break;
		}
	}

	//diagonals
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		winner = board[0][0];
	}
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		winner = board[0][2];
	}
}


int main()
{
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '},
	};

	const char playerX = 'X';
	const char playerO = 'O';
	char currentPlayer = playerX;

	int r = -1;
	int c = -1;

	char winner = ' ';

	for (int i = 0; i < 9; i++) {
		printBoard(board);

		if (winner != ' ') {
			break;
		}


		//get player input
		cout << "Current Player is " << currentPlayer << endl;
		while (true)
		{
			cout << "Enter r c from 0 - 2 for row and column: ";
			cin >> r >> c; 
			if (r < 0 || r >2 || c < 0 || c > 2) {
				cout << "Invalid input, try again." << endl;
			}
			else if (board[r][c] != ' ') {
				cout << "tile is full, try again." << endl;
			}
			else{
				break;
			}
			//reset values
			r = -1;
			c = -1;
			// A B (strings) stucks their // clear input stream
			cin.clear();
			cin.ignore(10000, '\n');
			// skips to the new line \n up to 10000 char which are already in stream
		}

		board[r][c] = currentPlayer;
		currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

		checkWinner(board);
		
	}

	if (winner != ' ') {
		cout << "Player" << winner << " is the winner!" << endl;
	}
	else {
		cout << "Tie!"<< endl;
	}



	return 0;
}