#include <iostream>

// Making connect 4 shiddass



// For the game
char board[7][7] = { { ' ',' ',' ',' ',' ',' ',' ' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' } };

char selectColumn[7];

void menu();
void rules();
void drawBoard();
void gaming();
void resetBoard();

// Universal stuff
void clearCin();

// Main wil take the role as a menu
int main() {
	while (true) {
		int menuChoice{};


		switch (menuChoice)
		{
		default:
			break;
		}

		gaming();

	}
	return 0;
}

void rules() {

}

void drawBoard() {
	int i = 0;
	int j = 0;

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			if (i == 0) {
				std::cout << "T" << board[i][j];
			}
			else {
				std::cout << "|" << board[i][j];
			}
		}
		if (i == 0) {
			std::cout << "T" << std::endl;
		}
		else {
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "---------------" << std::endl;
}

void gaming() {
	drawBoard();

}

void clearCin() {

}