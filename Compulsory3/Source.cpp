#include <iostream>
#include <conio.h>
#include <vector>

// Making connect 4 shiddass

// For the game
std::vector<std::vector<char>> board;

int arrowPosX = 0;
int arrowPosY = 0; // variables are named wrong, but they work
char selectColumn = 'v';

void drawMenu();
std::string menu[2][3];

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
	board.push_back(std::vector<char>(7, '.'));
	board.push_back(std::vector<char>(7, '.'));
	board.push_back(std::vector<char>(7, '.'));
	board.push_back(std::vector<char>(7, '.'));
	board.push_back(std::vector<char>(7, '.'));
	board.push_back(std::vector<char>(7, '.'));

	while (true) {
		int menuChoice{};
		// We draw a cool title header
		std::cout << "Welcome to" << std::endl;
		std::cout << "  ____                                         _             __" << std::endl;
		std::cout << " / ___|   ___    _ __    _ __     ___    ___  | |_          / _|   ___    _   _   _ __" << std::endl;
		std::cout << "| |      / _ \\  | '_ \\  | '_ \\   / _ \\  / __| | __| _____  | |_   / _ \\  | | | | | '__|" << std::endl;
		std::cout << "| |___  | (_) | | | | | | | | | |  __/ | (__  | |_ |_____| |  _| | (_) | | |_| | | |" << std::endl;
		std::cout << " \\____|  \\___/  |_| |_| |_| |_|  \\___|  \\___|  \\__|        |_|    \\___/   \\__,_| |_|" << std::endl;

		switch (menuChoice) {
		case 'w':

			break;
		default:
			break;
		}

		gaming();
		break;
	}
	return 0;
}

// Shall draw the menu and allow user to select a few option
void drawMenu() {
	std::cout << "---------------" << std::endl;
	for (int i{}; i < 3; i++) {
		//std::cout << board[i] << " |";				// Once it's done placing the three slots it goes out of the inner loop
																	// and into the outer loop which contains the std::endl at the end of each loop
		std::cout << std::endl << "---------------" << std::endl;   //
	}
}

// Show user the rules of the game
void rules() {

}

// Draw the playing field
void drawBoard() {
	int i = 0;
	int j = 0;

	arrowPosX = 0; // Set to 0 so the arrow always is at the top of the board
	
	for (i = 0; i < board.size(); i++) { // Checks the outer vector
		for (j = 0; j < board.at(i).size(); j++) { // Checks the vector at position i
			if (i == 0) { // Only affects to row of the board (I think)
				board[i][j] = ' '; // Draw an empty space where the arrow pointer was and where it isn't
				if (i == arrowPosX && j == arrowPosY) { // We draw the arrow pointer at the correct x y position
					board[i][j] = selectColumn;
					//std::cout << board.at(arrowPosX).at(arrowPosY);
				}
			}
			std::cout << "|" << board.at(i).at(j);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

// Main function used for playing the game
void gaming() {
	char move{};

	while (true) {
		//std::cout << board.size()<< std::endl;
		//system("cls");
		std::cout << "Use 'a' or 'd' to move the pointer; 'v' left or right respectively.\n";
		std::cout << "Then you can press ENTER or SPACE to select the highlighted column.\n";
		std::cout << "Or you can use number keys 1 through 7 to instantly select the column you want" << std::endl;
		drawBoard();
		move = _getch();
		move = tolower(move);
		switch (move) {
		// First two cases 'a' and 'd' allows user to move pointer left and right, respectively, over different columns
		case 'a':
			arrowPosY--;
			if (arrowPosY < 0) {
				arrowPosY = (board.size() - 1);
			}
			break;
		case 'd':
			arrowPosY++;
			if (arrowPosY > (board.size() - 1)) {
				arrowPosY = 0;
			}
			break;
		// Pressing ENTER will place a token in the column that the player has highlighted
		// 13 is the key code for ENTER
		case 13: case 32:
			std::cout << "You pressed ENTER";
			placeToken(move);
			break;
		// The numbered cases allow user to select a column using the number keys
		case '1':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '2':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '3':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '4':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '5':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '6':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '7':
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		default:
			std::cout << "Please use one of the specified inputs" << std::endl << std::endl;
			break;
		}
		std::cout << arrowPosX << "\t" << arrowPosY << std::endl;
	}
}

// Will move the token to the bottom of a column
void placeToken(char a) {

	// ENTER or SPACE input
	if (a == 13 || a == 32) {
		board.at(arrowPosX + 1).at(arrowPosY) = 'X';
	
	
	}


}

// Reset the playing field
void resetBoard() {

}

// Clear cin buffer
void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}