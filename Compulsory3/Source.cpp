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
							{" ", " 3. Stats"},
							{" ", " 4. Quit"} };

// This collection is displayed on the menu in some form
void whoIsGaming(); // Insert name of players, we will try to save them and their scores. Will go to gaming when finished
void rules(); // Display the rules
void viewStats(); // Display stats
void quit(); // Terminate program 

// Functions for the game
void gaming(); // Play the game
void drawBoard(); // draw the board
void placeToken(char); // Place player token correctly
void winConditions(); // Check for lines of 4
void resetBoard(); // Empty the board of tokens

// Universal stuff
void clearCin();

// Daddy Johannes explains referencing
void referenceExample(int& OUTint, char& OUTchar);

// Main wil take the role as a menu
int main() {
	stats.close();
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

		std::cout << "Use 'w' and 's' to move up or down, press SPACE or ENTER to confirm highlighted option, or you can use the numbers listed." << std::endl;
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
		// User pressed SPACE or ENTER
		case 13: case 32:
			switch (arrowPosY) {
			// Position 1
			case 0:
				whoIsGaming();
				gaming();
				break;
			// Position 2
			case 1:
				rules();
				break;
			// Position 3
			case 2:
				viewStats();
				break;
			// Position 4
			case 3:
				exit(0);
				break;
			default:
				std::cout << "Something is wrong..." << std::endl;
				break;
			}
			break;
		// Press ESC to close
		case 27:
			exit(0);
			break;
		default:
			std::cout << "Please use one of the specified inputs to navigate the menu." << std::endl;
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
	std::cin >> p2Name;

	stats.close();
}

// Shall draw the menu
void drawMenu() {
	for (int i{}; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == arrowPosY && j == arrowPosX) {
				menu[i][0] = menuArrow;
			}
			else {
				menu[i][0] = " ";
			}
			std::cout << menu[i][j];				
		}								
		std::cout << std::endl;
	}
}

// Show user the rules of the game
void rules() {
	std::cout << "Connect-four is a 2 player game; you will either play against a human or an AI" << std::endl;
	std::cout << "(The AI is probably more A than I)" << std::endl;
	std::cout << "You and your oppoent will drop tokens to the bottom of the board and try to get a line of four." << std::endl;
}

void viewStats() {

	stats.close();
}

void quit(){
	exit(0);

}

// Draw the playing field
void drawBoard() {
	arrowPosY = 0; // Set to 0 so the arrow always is at the top of the board
	
	for (int y = 0; y < board.size(); y++) { // Checks the outer vector, 
		for (int x = 0; x < board.at(y).size(); x++) { // Checks the vector at position i
			if (y == 0) { // Only affects top row of the board (I think)
				board[y][x] = ' '; // Draw an empty space where the arrow pointer was and where it isn't
				if (y == arrowPosY && x == arrowPosX) { // We draw the arrow pointer at the correct x y position
					board[y][x] = selectColumn;
				}
			}
			std::cout << "|" << board.at(y).at(x);
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------" << std::endl; // The floor
}

// Main function used for playing the game
void gaming() {
	char move{};
	system("cls");
	while (true) {
		
		std::cout << "Use 'a' or 'd' to move the pointer; 'v' left or right respectively.\n";
		std::cout << "Then you can press ENTER or SPACE to select the highlighted column.\n";
		std::cout << "Or you can use number keys 1 through 7 to instantly select the column you want" << std::endl;
		drawBoard();
		winConditions();
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
		case 13: case 32:
			std::cout << "You pressed ENTER";
			placeToken(move);
			break;
		// The numbered cases allow user to select a column using the number keys
		case '1':
			arrowPosX = 0;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '2':
			arrowPosX = 1;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '3':
			arrowPosX = 2;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '4':
			arrowPosX = 3;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '5':
			arrowPosX = 4;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '6':
			arrowPosX = 5;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		case '7':
			arrowPosX = 6;
			std::cout << "You selected:" << move << std::endl << std::endl;
			placeToken(move);
			break;
		// Forfeit the game
		case 27:

			break;
		default:
			std::cout << "Please use one of the specified inputs to navigate the board." << std::endl << std::endl;
			break;
		}
		std::cout << arrowPosY << "\t" << arrowPosX << std::endl;
	}
}

// Will move the token to the bottom of a column
void placeToken(char a) {
	std::cout << a << std::endl;
	switch (a){
	// ENTER or SPACE input
	case 13: case 32:
		// Loop will run through inner vector from bottom to top
		for (arrowPosY = 6; arrowPosY >= 0; arrowPosY--) {
			// If a spot in vector is '.' it will place a token and break out of the loop
			if (board.at(arrowPosY).at(arrowPosX) == '.') {
				board.at(arrowPosY).at(arrowPosX) = 'X';
				break;
			}
		}
		break;
	// Number input
	case '1': case '2': case '3': case '4': case '5': case '6': case '7':
		// Loop will run through inner vector from bottom to top
		for (arrowPosY = 6; arrowPosY >= 0; arrowPosY--) {
			// If a spot in vector is '.' it will place a token and break out of the loop
			if (board.at(arrowPosY).at(arrowPosX) == '.') {
				board.at(arrowPosY).at(arrowPosX) = 'X';
				break;
			}
		}
		break;
	default:
		std::cout << "Something is wrong...\n" << std::endl;
		break;
	}
	winConditions(); // run before resetting arrowPosY so I can check that spesific position.
	arrowPosY = 0;
}

// $$$$$
void winConditions() {
	int count = 0;

	// Check vertically (up and down)
		for (int y = 0; y < board.size() - 3; y++) { // Checks the outer vector, 
			for (int x = 0; x < board.at(y).size(); x++) { // Checks the vector at position i
				if (board[y][x] != '.') {
					if (board[y][x] == board[y + 1][x] && board[y + 1][x] == board[y + 2][x] && board[y + 2][x] == board[y + 3][x]) {
						std::cout << "Vertical win" << std::endl;
						break;
					}
				}
			}
		}
	
		//}
	
	// Check horizontal (left to right)
	

	// Check up right

	/*	int y = arrowPosY;
		int x = arrowPosX;*/
			/*if (board[y][x]) {

			}*/
			

	// Check up left
		
		/*int y = arrowPosY;
		int x = arrowPosX;*/
	//std::cout << y << "\t" << x << std::endl << std::endl;
	
	
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