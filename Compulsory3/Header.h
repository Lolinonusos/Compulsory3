#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

// Making connect 4 shiddass

class Player {
public:

	std::string name{};
	int wins{};
	int draws{};
	int forfeits{};

	//void printName() {
	//	std::cout << name;
	//}

private:

};

std::vector <Player> players;

std::string p1Name{};
std::string p2Name{};

// For the game
std::vector<std::vector<char>> board;

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
void whoIsGaming(); // Who TF be gamin tho, go to select which names will be used or if you are gonna create new names. Will go to gaming when finished
void createPlayerName(); // Enter a new name, will also create a new Player object
void selectExistingGamer(); // Select the names
void listOfExistingNames(); // Create the list of names
int selectedNameP1{}; // selected name will also let me save stats to the name selected
int selectedNameP2{};
void rules(); // Display the rules
void viewStats(); // Display stats

// Functions for the game
void gaming(); // Play the game
int turn = 1; // P1 = 1	  P2 = 2
bool forfeit = false;
bool draw = false; // Is true when board is filled and win still is false
void drawBoard(); // draw the board
void placeToken(char); // Place player token correctly
void winConditions(); // Check for lines of 4, and change bools to true
bool win = false;
void resetBoard(); // Empty the board of tokens

// AI
char RNGesus();

// Universal stuff
void clearCin();

// Daddy Johannes explains referencing
void referenceExample(int& OUTint, char& OUTchar);