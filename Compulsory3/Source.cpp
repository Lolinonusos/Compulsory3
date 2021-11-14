#include "Header.h"

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

		std::cout << "Use 'w' and 's' to move up or down, press SPACE or ENTER to confirm highlighted option, or you can use the numbers listed." << std::endl;
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
		// Press 'q' to close
		case 'q':
			exit(0);
			break;
		default:
			std::cout << "Please use one of the specified inputs to navigate the menu." << std::endl;
			break;
		}
		if (arrowPosX > 0) {
			arrowPosX = 0;
		}
	}
	return 0;
}

void whoIsGaming() {
	if (players.size() != 0) {
		char yn = '0';
		do {
			std::cout << "1. Select from existing names" << std::endl;
			std::cout << "2. Create new names" << std::endl;
			yn = _getch();
			switch (yn) {
			case '1':
				selectExistingGamer();
				break;
			case '2':
				createPlayerName();
				break;
			default:
				break;
			}
		} while (yn != '1');

	}
	else if (players.size() == 0) {
		createPlayerName();
	}
}

void selectExistingGamer() {
	std::cout << "Input the number of which name you want:\n" << std::endl;
	listOfExistingNames();
	std::cout << "\n" << std::endl;
	std::cout << "Player One, select your name: " << std::endl;
	std::cin >> selectedNameP1;
	std::cout << "Player One is " << players.at(selectedNameP1).name << std::endl << std::endl;
	std::cout << "PLayer Two, select your name: " << std::endl;
	std::cin >> selectedNameP2;
	std::cout << "Player Two is " << players.at(selectedNameP2).name << std::endl << std::endl;
}

void listOfExistingNames() {
	for (size_t i = 0; i < players.size(); i++) {
		std::cout << i << ". " << players.at(i).name << std::endl;
	}
}
	
void createPlayerName() {

	do {
		Player temp_player;
		std::cout << "Who is gaming today?\n" << std::endl;
		if (players.size() == 0) {
			std::cout << "Player 1: ";
			selectedNameP1 = 0;
		}
		else if (players.size() == 1) {
			std::cout << "(If you set P2's name to AI it will be controlled by the CPU)" << std::endl;
			std::cout << "Player 2: ";
			selectedNameP2 = 1; // Must be set to one or else it will pick the name on slot 0 in the vector
		}
		else {
			std::cout << "New name: ";
		}
		std::cin >> temp_player.name;
		temp_player.wins = 0;
		temp_player.draws = 0;
		temp_player.forfeits = 0;

		players.push_back(temp_player);


		std::cout << std::endl;
	} while (players.size() <= 1);

	std::cout << players.at(0).name;
		std::cout << players.at(1).name;

	
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
	char next{};
	next = _getch();
}

// Vies stats and names of players
void viewStats() {
	// Foldering, currently not doing anything with the file :(
	std::string read{};
	std::streampos begin, end;
	std::fstream stats("../Names_And_Stats.txt", std::ios::in | std::ios::app | std::ios::out); // Se etter en bedre måte
	system("clear");
	stats << "Name:\t" << "Wins:\t" << "Draws:\t" << "Forfeits:\t" << std::endl << std::endl;
	for (int i = 0; i < players.size(); i++) {
		stats << players.at(i).name << "\t" << players.at(i).wins << "\t" << players.at(i).draws << "\t" << players.at(i).forfeits;
		stats << std::endl << std::endl;
	}
	stats.clear();
	stats.seekg(0);
	while (getline(stats, read)) {
			// read stuff from the file into a string and print it
			std::cout << read << '\n';
	}
	std::cout << std::endl;

	stats.close();

	std::cout << std::endl << "Press anything to return to menu." << std::endl;
	char next{};
	next = _getch();
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
	char yn = 'y';
	turn = 1; // P1 always starts
	while (yn == 'y')
	{
		win = false;
		draw = false;
		forfeit = false;

		while (win != true) {
			system("cls");

			// Spelling out whose turn it is
			switch (turn) {
			case 1:
				std::cout << "It is " << players.at(selectedNameP1).name << "'s turn.\n" << std::endl;
				std::cout << "You place X\n" << std::endl;
				std::cout << "Use 'a' or 'd' to move the pointer; 'v' left or right respectively.\n";
				std::cout << "Then you can press ENTER or SPACE to select the highlighted column.\n";
				std::cout << "Or you can use number keys 1 through 7 to instantly select the column you want\n" << std::endl;
				drawBoard();
				move = _getch();
				move = tolower(move);
				break;
			case 2:
				std::cout << "It is " << players.at(selectedNameP2).name << "'s turn.\n" << std::endl;
				std::cout << "You place O\n" << std::endl;
				std::cout << "Use 'a' or 'd' to move the pointer; 'v' left or right respectively.\n";
				std::cout << "Then you can press ENTER or SPACE to select the highlighted column.\n";
				std::cout << "Or you can use number keys 1 through 7 to instantly select the column you want\n" << std::endl;
				
				if (players.at(selectedNameP2).name != "AI") {
					drawBoard();
					move = _getch();
					move = tolower(move);
				}
				// If P2 is AI
				if (players.at(selectedNameP2).name == "AI") {
					RNGesus();
					move = RNGesus();
				}
				break;
			}
		
			// First two cases 'a' and 'd' allows user to move pointer left and right, respectively, over different columns
			switch (move) {
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
				placeToken(move);	
				break;
			// The numbered cases allow user to select a column using the number keys
			case '1':
				arrowPosX = 0;
				placeToken(move);
				break;
			case '2':
				arrowPosX = 1;
				placeToken(move);
				break;
			case '3':
				arrowPosX = 2;
				placeToken(move);
				break;
			case '4':
				arrowPosX = 3;
				placeToken(move);
				break;
			case '5':
				arrowPosX = 4;
				placeToken(move);
				break;
			case '6':
				arrowPosX = 5;
				placeToken(move);
				break;
			case '7':
				arrowPosX = 6;
				placeToken(move);
				break;
			// Pressing 'q' will forfeit the game
			case 'q':
				win = true;
				forfeit = true;
				break;
			default:
				std::cout << "Please use one of the specified inputs to navigate the board." << std::endl << std::endl;
				break;
			}
			if (draw == true) {
				system("cls");
				std::cout << "Draw\n\n\n\n\n\n\n" << std::endl;
				drawBoard();
				break;
			}
		}
		if (forfeit == true) {
			std::cout << "Player forfeited the game.\n" << std::endl;
			switch (turn) {
			case 1:
				players.at(selectedNameP1).forfeits += 1;
				break;
			case 2:
				players.at(selectedNameP2).forfeits += 1;
				break;
			}
		}

		resetBoard();
		
		std::cout << "Do you want to play another game?\nPress 'y' to start a new game" << std::endl;
		
		std::cin >> yn;
	}
}

// AI
char RNGesus() {
	int a{};
	char b{};

	// Curently just places tokens randomly
	std::srand(time(0));
	a = rand() % 7 + 1;

	switch (a) {
	case 1:
		b = '1';
		break;
	case 2:
		b = '2';
		break;
	case 3:
		b = '3';
		break;
	case 4:
		b = '4';
		break;
	case 5:
		b = '5';
		break;
	case 6:
		b = '6';
		break;
	case 7:
		b = '7';
		break;
	default:
		break;
	}
	return b; // Need to return char because int in gaming needs char?
}

// Will move the token to the bottom of a column
void placeToken(char a) {
	// User cannot select a column that has been completely filled
	if (board[1][arrowPosX] == '.') {
		switch (a){
		// ENTER or SPACE input
		case 13: case 32:
			// Loop will run through inner vector from bottom to top
			for (arrowPosY = 6; arrowPosY >= 0; arrowPosY--) {
				// If a spot in vector is '.' it will place a token and break out of the loop
				if (board.at(arrowPosY).at(arrowPosX) == '.') {
					if (turn == 1) {
						board.at(arrowPosY).at(arrowPosX) = 'X';
					}
					else if (turn == 2) {
						board.at(arrowPosY).at(arrowPosX) = 'O';
					}
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
					if (turn == 1) {
						board.at(arrowPosY).at(arrowPosX) = 'X';
					}
					else if (turn == 2) {
						board.at(arrowPosY).at(arrowPosX) = 'O';
					}
					break;
				}
			}
			break;
		default:
			std::cout << "Something is wrong...\n" << std::endl;
			break;
		}
		winConditions(); 
		// Changes which players turn it is only when placing token is successful
		if (turn == 1) {
			turn = 2;
		}
		else if (turn == 2) {
			turn = 1;
		}
		arrowPosY = 0;
	}

	else {
		std::cout << "That column is full, select another." << std::endl;
	}
}

// $$$$$
void winConditions() {
	// Check vertically (up and down)
	for (int y = 0; y < board.size() - 3; y++) { // Checks the outer vector, 
		for (int x = 0; x < board.at(y).size(); x++) { // Checks the vector at position i
			if (board[y][x] != '.') {
				if (board[y][x] == 'X' && board[y][x] == board[y + 1][x] && board[y + 1][x] == board[y + 2][x] && board[y + 2][x] == board[y + 3][x]) {
					system("cls"); 
					std::cout << "P1 Vertical win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP1).wins += 1;
					win = true;
					break;
				}
				if (board[y][x] == 'O' && board[y][x] == board[y + 1][x] && board[y + 1][x] == board[y + 2][x] && board[y + 2][x] == board[y + 3][x]) {
					system("cls");
					std::cout << "P2 Vertical win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP2).wins += 1;
					win = true;
					break;
				}
			}
		}
	}
	
	// Check horizontal (left to right)
	for (int y = 1; y < board.size(); y++) {
		for (int x = 0; x < board.at(y).size() - 3; x++) {
			if (board[y][x] != '.') { 
				if (board[y][x] == 'X' && board[y][x] == board[y][x + 1] && board[y][x + 1] == board[y][x + 2] && board[y][x + 2] == board[y][x + 3]) {
					system("cls");
					std::cout << "P1 Horizontal win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP1).wins += 1;
					win = true;
					break;
				}
				if (board[y][x] == 'O' && board[y][x] == board[y][x + 1] && board[y][x + 1] == board[y][x + 2] && board[y][x + 2] == board[y][x + 3]) {
					system("cls");
					std::cout << "P2 Horizontal win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP2).wins += 1;
					win = true;
					break;
				}
			}
		}
	}

	// Check diagonal leaning left (
	for (int y = 1; y < board.size()-3; y++) {
		for (int x = 0; x < board.at(y).size()-3; x++) {
			if (board[y][x] != '.') {
				if (board[y][x] == 'X' && board[y][x] == board[y + 1][x + 1] && board[y +1][x + 1] == board[y + 2][x + 2] && board[y + 2][x + 2] == board[y + 3][x + 3]) {
					system("cls");
					std::cout << "P1 Diagonal leaning left win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP1).wins += 1;
					win = true;
					break;
				}
				if (board[y][x] == 'O' && board[y][x] == board[y + 1][x + 1] && board[y + 1][x + 1] == board[y + 2][x + 2] && board[y + 2][x + 2] == board[y + 3][x + 3]) {
					system("cls");
					std::cout << "P2 Diagonal leaning left win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP2).wins += 1;
					win = true;
					break;
				}
			}
		}
	}

	// Check diagonal leaning right
	for (int y = 1; y < board.size(); y++) {
		for (int x = 0; x < board.at(y).size() - 3; x++) { 
			if (board[y][x] != '.') {
				if (board[y][x] == 'X' && board[y][x] == board[y - 1][x + 1] && board[y - 1][x + 1] == board[y - 2][x + 2] && board[y - 2][x + 2] == board[y - 3][x + 3]) {
					system("cls");
					std::cout << "P1 Diagonal leaning right win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP1).wins += 1;
					win = true;
					break;
				}
				if (board[y][x] == 'O' && board[y][x] == board[y - 1][x + 1] && board[y - 1][x + 1] == board[y - 2][x + 2] && board[y - 2][x + 2] == board[y - 3][x + 3]) {
					system("cls");
					std::cout << "P2 Diagonal leaning right win\n\n\n\n\n\n\n" << std::endl;
					drawBoard();
					players.at(selectedNameP2).wins += 1;
					win = true;
					break;
				}
			}
		}
	}

	// Check for draw
		int drawCount = 0;
		for (int x = 0; x < board.at(1).size(); x++) {
			if (board[1][x] != '.') {
				drawCount += 1;
			}
			if (drawCount == board.at(1).size()) {
				players.at(selectedNameP1).draws += 1;
				players.at(selectedNameP2).draws += 1;
				draw = true;
			}
		}
	
}

// Reset the playing field
void resetBoard() {
	// Using the quick fix method for now
	char resetter[7][7] = { {' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{'.', '.', '.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.', '.', '.'},
							{'.', '.', '.', '.', '.', '.', '.'}, };

	// Just sets the elements in the vector to be the same as in this array
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			board[y][x] = resetter[y][x];
		}
	}
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