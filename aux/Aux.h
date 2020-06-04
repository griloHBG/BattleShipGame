#ifndef AUX_H
#define AUX_H
// Libraries

// # Native
#include <iostream>  // cout, endl => Purpose: printing text in the screen
#include <ncurses.h> // getch => Purpose: enables user interface in terminal
#include <algorithm> // transform => Purpose: used to calculate operations between sequences
#include <memory>    // make_shared => Purpose: allocates a pointer for a certain type of class
#include <cstdlib>   //random() => Purpose: generate random numbers
#include <ctime>     //time => Purpose: get and manipulate time
//#include <random> //random_device, mt19937, uniform_int_distribution

// # Files made by the application
#include "../board/Board.h"
#include "../ships/submarine/Submarine.h"
#include "../ships/destroyer/Destroyer.h"
#include "../ships/carrier/Carrier.h"
#include "../ships/hydroPlane/HydroPlane.h"
#include "../ships/cruiser/Cruiser.h"
#include "../ships/ShipType.h"
#include "../general/General.h"

// #define clearScreen() system("CLS") - Windows command for clearing the screen (cls)
#define clearScreen() system("clear") // Linux command for clearing the screen (clear)

// Types of actions in the game
enum CommandType
{
  PLACE,
  REMOVE,
  INVALID
};

// Generating a random number.
// uint8_t is a type variable that indicates precisely that it is an unsigned single-byte (8 bits) integer. Number between 0 and 255
// Preciseness never hurt anyone :)
int randomNumberGenerator(uint8_t low, uint8_t high);

// Function to acknowledge some message
void getAcknowledgement(std::stringstream &ssScreen);

void confirmPassword(std::stringstream &ssScreen, const std::string &password);

bool getYesOrNo(std::stringstream &ssScreen);

std::string unitType_to_string(UnitType unitType);

void placeUnits(General &general, Board *board, bool doRandomizeUNITS);

#endif
/* AUX_H */