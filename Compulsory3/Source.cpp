#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>

// Making connect 4 shiddass

class Player {
public:

	std::string name{};
	int wins{};
	int draws{};
	int forfeit{};

private:

};


std::vector <Player> players;

// For the game
std::vector<std::vector<char>> board;

// Foldering
std::string buffer{};
std::streampos begin, end;
std::fstream stats("../Names_And_Stats.txt", std::ios::in | std::ios::app | std::ios::out); // Se etter en bedre måte

// Keycodes
// SPACE = 32
// ENTER = 13
// ESC = 27
int arrowPosX = 0;
int arrowPosY = 0;
std::string menuArrow = "-> ";
char selectColumn = 'v';

void drawMenu();
std::string menu[4][2] = { { " ", " 1. Play"},
							{" ", " 2. Rules"},
							{" ", " 3. Highscores"},
							{" ", " 4. Quit"} };

// This collection is displayed on the menu in some form
void whoIsGaming(); // Insert name of players, we will try to save them and their scores. Will go to gaming when finished
void rules(); // Display the rules
void viewScores(); // Display scores
void quit(); // Terminate program 

// Functions for the game
void gaming(); // Play the game
void drawBoard(); // draw the board
void placeToken(char); // Place player token correctly
void winConditions(); // Check for lines of 4
void resetBoard(); // Empty the board of tokens

// Universal stuff
void clearCin();

void referenceExample(int& OUTint, char& OUTchar);

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

	arrowPosX = 0;
	arrowPosY = 0;

	while (true) {
		system("cls");

		int menuChoice{};

		// We draw a cool title header
		std::cout << "Welcome to" << std::endl;
		std::cout << "  ____                                         _             __" << std::endl;
		std::cout << " / ___|   ___    _ __    _ __     ___    ___  | |_          / _|   ___    _   _   _ __" << std::endl;
		std::cout << "| |      / _ \\  | '_ \\  | '_ \\   / _ \\  / __| | __| _____  | |_   / _ \\  | | | | | '__|" << std::endl;
		std::cout << "| |___  | (_) | | | | | | | | | |  __/ | (__  | |_ |_____| |  _| | (_) | | |_| | | |" << std::endl;
		std::cout << " \\____|  \\___/  |_| |_| |_| |_|  \\___|  \\___|  \\__|        |_|    \\___/   \\__,_| |_|" << std::endl << std::endl << std::endl;

		std::cout << arrowPosX << "\t" << arrowPosY << std::endl;
		drawMenu();
		menuChoice = _getch();
		switch (menuChoice) {
		case 'w':
			arrowPosY--;
			if (arrowPosY < 0) {
				arrowPosY = 3;
			}
			break;
		case 's':
			arrowPosY++;
			if (arrowPosY > 3) {
				arrowPosY = 0;
			}
			break;
		case 13: case 32:
			if (arrowPosY == 0) {
				whoIsGaming();
				gaming();
			}
			if (arrowPosY == 1) {
				rules();
			}
			if (arrowPosY == 2) {
				viewScores();
			}
			if (arrowPosY == 3) {
				exit(0);
			}
			break;
		// Press ESC to close
		case 27:
			exit(0);
			break;
		default:
			std::cout << "Other button pls." << std::endl;
			break;
		}
	}
	return 0;
}

void whoIsGaming() {

	std::string p1Name{};
	std::string p2Name{};


	std::cout << "Who is gaming today?\n" << std::endl;
	std::cout << "Player 1: ";
	std::cin >> p1Name;
	std::cout << std::endl;
	std::cout << "Player 2: ";
	std::cout << p2Name;

	stats.close();
}

// Shall draw the menu and allow user to select a few option
void drawMenu() {
	for (int i{}; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == arrowPosY && j == arrowPosX) {
				menu[i][0] = menuArrow;
				//std::cout << menu[arrowPosX][arrowPosY];
			}
			else {
				menu[i][0] = " ";
			}
			std::cout << menu[i][j];				// Once it's done placing the three slots it goes out of the inner loop
		}								// and into the outer loop which contains the std::endl at the end of each loop
		std::cout << std::endl;
	}
}

// Show user the rules of the game
void rules() {

}

void viewScores() {

}

void quit()
{
}

// Draw the playing field
void drawBoard() {
	int i = 0;
	int j = 0;

	arrowPosY = 0; // Set to 0 so the arrow always is at the top of the board
	
	for (i = 0; i < board.size(); i++) { // Checks the outer vector
		for (j = 0; j < board.at(i).size(); j++) { // Checks the vector at position i
			if (i == 0) { // Only affects to row of the board (I think)
				board[i][j] = ' '; // Draw an empty space where the arrow pointer was and where it isn't
				if (i == arrowPosY && j == arrowPosX) { // We draw the arrow pointer at the correct x y position
					board[i][j] = selectColumn;
				}
			}
			std::cout << "|" << board.at(i).at(j);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------" << std::endl; // The floor
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
			arrowPosX--;
			if (arrowPosX < 0) {
				arrowPosX = (board.size() - 1);
			}
			break;
		case 'd':
			arrowPosX++;
			if (arrowPosX > (board.size() - 1)) {
				arrowPosX = 0;
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
		// Forfeit the game
		case 27:

			break;
		default:
			std::cout << "Please use one of the specified inputs" << std::endl << std::endl;
			break;
		}
		std::cout << arrowPosY << "\t" << arrowPosX << std::endl;
	}
}

// Will move the token to the bottom of a column
void placeToken(char a) {

	// ENTER or SPACE input
	if (a == 13 || a == 32) {
		board.at(arrowPosY + 1).at(arrowPosX) = 'X';
	
	
	}


}

// $$$$$
void winConditions() {
}

// Reset the playing field
void resetBoard() {

}

// Clear cin buffer
void clearCin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

// Johannes hjelp :)
void referenceExample(int& OUTint, char& OUTchar)
{
	OUTint = 3;
}
