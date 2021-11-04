#include <iostream>
#include <conio.h>
#include <vector>
// Making connect 4 shiddass



// For the game
std::vector<std::vector<char>> board;
/* = { { ' ',' ',' ',' ',' ',' ',' ' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' },
					 { '.','.','.','.','.','.','.' } };*/

int arrowPosX = 0;
int arrowPosY = 0;
char selectColumn = 'v';

void menu();
void rules();
void drawBoard();
void gaming();
void placeToken(char);
void resetBoard();

// Universal stuff
void clearCin();

// Main wil take the role as a menu
int main() {

	// This is how you make a 2D vector
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));
	board.push_back(std::vector<char>(7, ' '));


	while (true) {
		int menuChoice{};


		switch (menuChoice)
		{
		default:
			break;
		}

		gaming();
		break;
	}
	return 0;
}

void rules() {

}

void drawBoard() {
	int i = 0;
	int j = 0;

	
	for (i = 0; i < board.size(); i++) { // Checks the outer vector
		for (j = 0; j < board.at(i).size(); j++) { // Checks the vector at position i
			board.at(i).at(j) = '.'; // Draws periods troghout the vector
			if (i == arrowPosX && j == arrowPosY) { // We draw the arrow pointer at the correct x y position
				board[i][j] = selectColumn;
			}
			/*else {
				board[i][j] = '.';
			}*/
			std::cout << "|" << board.at(i).at(j);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void gaming() {
	char move{};

	while (true) {
		system("cls");
		std::cout << "Use 'a' or 'd' to move pointer left or right respectively.\n";
		std::cout << "Press enter to select the column you have highlighted.\n";
		std::cout << "Or you can use number keys 1 through 7 to instantly select the column you want" << std::endl;
		drawBoard();
		move = _getch();
		move = tolower(move);
		switch (move) {
			// First two cases 'a' and 'd' allows users to move pointers over different columns
		case 'a':
			arrowPosY--;
			if (arrowPosY < 0) {
				arrowPosY = board.size() - 1;
			}
			break;
		case 'd':
			arrowPosY++;
			if (arrowPosY > (board.size() - 1)) {
				arrowPosY = 0;
			}
			break;
		case '1':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '2':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '3':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '4':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '5':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '6':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		case '7':
			std::cout << "You selected:" << move << std::endl << std::endl;
			break;
		default:
			std::cout << "Use one of the specified inputs please" << std::endl << std::endl;
			break;
		}

	}
}

void clearCin() {

}