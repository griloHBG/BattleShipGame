#include <iostream> //cout, endl
#include "Field.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Carrier.h"
#include "HydroPlane.h"
#include "Cruiser.h"
#include <ncurses.h> //getch
#include <algorithm> //transform
#include <memory>    // make_shared
#include "ShipType.h"
#include "General.h"
//#include <random> //random_device, mt19937, uniform_int_distribution
#include <cstdlib> //random()
#include <ctime>   //time

#define clearScreen() system("CLS")

enum CommandType
{
    PLACE,
    REMOVE,
    INVALID
};

//NOT WORKING
/*
uint8_t randomNumberGenerator(uint8_t low, uint8_t high)
{
    static std::random_device dev;
    static std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(low, high); // distribution in range [1, 6]

    int random_int = dist(rng);

    //std::cout << static_cast<int>(random_int) << std::endl;

    return random_int;
}
 */

int randomNumberGenerator(uint8_t low, uint8_t high)
{
    int random_int = (rand() % (high - low)) + low;

    return random_int;
}

void getAcknowledgement(std::stringstream &ssScreen)
{
    std::string playerInput;
    bool firstTime = true;

    do
    {
        if (firstTime)
        {
            firstTime = false;
        }
        else
        {
            std::cout << "Please, acknowledge the following message:" << std::endl
                      << std::endl;
        }

        std::cout << std::endl;
        std::cout << ssScreen.str();
        std::cout << std::endl;
        std::cout << "ACKNOWLEDGEMENT: " << std::endl;
        std::cin >> playerInput;

        std::cin.seekg(0, std::ios::end);
        std::cin.clear();

        clearScreen();

    } while (playerInput != "ack" && playerInput != "ACK");
}

//doesn't work!
/*
std::ostream& operator<<(std::ostream& out, const UnitType& unitType)
{
    switch(unitType)
    {
        case CARRIER:
            out << "CARRIER";
            break;
        case CRUISER:
            out << "CRUISER";
            break;
        case HYDROPLANE:
            out << "HYDRO PLANE";
            break;
        case DESTROYER:
            out << "DESTROYER";
            break;
        case SUBMARINE:
            out << "SUBMARINE";
            break;
    }

    return out;
}
 */

void confirmPassword(std::stringstream &ssScreen, const std::string &password)
{
    std::string playerInput;
    bool firstTime = true;

    do
    {
        if (firstTime)
        {
            firstTime = false;
        }
        else
        {
            std::cout << "PASSWORD INCORRECT! Please enter your password." << std::endl
                      << std::endl;
        }

        std::cout << ssScreen.str();
        std::cout << std::endl;
        std::cout << "PASSWORD: " << std::endl;
        std::cin >> playerInput;

        std::cin.seekg(0, std::ios::end);
        std::cin.clear();

        clearScreen();

    } while (playerInput != password);

    std::cout << "PASSWORD CORRECT!" << std::endl;
    std::cout << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    getch();
}

bool getYesOrNo(std::stringstream &ssScreen)
{
    std::string playerInput;
    bool firstTime = true;

    do
    {
        if (firstTime)
        {
            firstTime = false;
        }
        else
        {
            std::cout << "Please enter YES or NO, Sir." << std::endl
                      << std::endl;
        }

        std::cout << ssScreen.str();
        std::cout << std::endl;
        std::cout << "ANSWER: " << std::endl;
        std::cin >> playerInput;

        std::cin.seekg(0, std::ios::end);
        std::cin.clear();

        clearScreen();

        std::transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::toupper);

    } while (playerInput != "YES" && playerInput != "NO");

    return (playerInput == "YES");
}

std::string unitType_to_string(UnitType unitType)
{
    std::string result;

    switch (unitType)
    {
    case CARRIER:
        result = "CARRIER";
        break;
    case CRUISER:
        result = "CRUISER";
        break;
    case HYDROPLANE:
        result = "HYDRO PLANE";
        break;
    case DESTROYER:
        result = "DESTROYER";
        break;
    case SUBMARINE:
        result = "SUBMARINE";
        break;
    }

    return result;
}

void placeUnits(General &general, Field *field, bool doRandomizeUNITS)
{
    if (!doRandomizeUNITS)
    {
        bool inputFailed;
        bool cantUseUnit;
        CommandType command;

        std::string sCommand, sShip, sPosition, sDirection;

        Field *auxField = new Field();

        Ship *ship = nullptr;
        UnitType unitType;

        do
        {
            inputFailed = false;
            cantUseUnit = false;
            command = CommandType::INVALID;

            ShipDirection direction;

            std::cout << "GENERAL " << general << ", these are UNITS you still have available, Sir:" << std::endl
                      << std::endl
                      << std::setw(6) << general.getRemaining(UnitType::CARRIER) << std::setw(13) << "CARRIER"
                      << "\t( 5 cells )" << std::endl
                      << std::setw(6) << general.getRemaining(UnitType::CRUISER) << std::setw(13) << "CRUISERS"
                      << "\t( 4 cells )" << std::endl
                      << std::setw(6) << general.getRemaining(UnitType::HYDROPLANE) << std::setw(13) << "HYDRO PLANES"
                      << "\t( 3 cells )" << std::endl
                      << std::setw(6) << general.getRemaining(UnitType::DESTROYER) << std::setw(13) << "DESTROYERS"
                      << "\t( 2 cells )" << std::endl
                      << std::setw(6) << general.getRemaining(UnitType::SUBMARINE) << std::setw(13) << "SUBMARINES"
                      << "\t( 1 cells )" << std::endl
                      << std::endl
                      << *auxField << std::endl
                      << std::endl
                      << std::endl
                      << "To PLACE on the FIELD:             place carrier b5 west" << std::endl
                      << "                                   place Destroyer n10 east" << std::endl
                      << "                                   place submarine D8 south" << std::endl
                      << std::endl
                      << std::endl
                      << "To REMOVE position on the FIELD:   remove carrier b5" << std::endl
                      << "                                   remove DESTROYER n10" << std::endl
                      << "                                   remove submarine D8" << std::endl
                      << std::endl;

            std::cin >> sCommand >> sShip >> sPosition;

            std::transform(sCommand.begin(), sCommand.end(), sCommand.begin(), ::toupper);
            std::transform(sPosition.begin(), sPosition.end(), sPosition.begin(), ::toupper);
            std::transform(sShip.begin(), sShip.end(), sShip.begin(), ::toupper);

            if (sCommand == "PLACE")
            {
                inputFailed = false;
                command = CommandType::PLACE;
            }
            else if (sCommand == "REMOVE")
            {
                inputFailed = false;
                command = CommandType::REMOVE;
            }
            else
            {
                inputFailed = true;
                command = CommandType::INVALID;

                clearScreen();

                std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection
                          << std::endl
                          << std::endl
                          << "    You must only use one of these command instructions:" << std::endl
                          << "                        PLACE  OR REMOVE" << std::endl
                          << std::endl;

                continue;
            }

            if (command == CommandType::REMOVE)
            {

                if (ship != nullptr)
                {
                    delete ship;
                }

                if (sShip == "CARRIER" || sShip == "CAR")
                {
                    unitType = UnitType::CARRIER;
                }
                else if (sShip == "CRUISER" || sShip == "CRU")
                {
                    unitType = UnitType::CRUISER;
                }
                else if (sShip == "HYDRO" || sShip == "HYDROPLANE" || sShip == "HYD")
                {
                    unitType = UnitType::HYDROPLANE;
                }
                else if (sShip == "DESTROYER" || sShip == "DES")
                {
                    unitType = UnitType::DESTROYER;
                }
                else if (sShip == "SUBMARINE" || sShip == "SUB")
                {
                    unitType = UnitType::SUBMARINE;
                }
                else
                {
                    inputFailed = true;

                    clearScreen();

                    std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << std::endl
                              << std::endl
                              << "    You must address to these, and only these, kind of UNITS:" << std::endl
                              << std::endl
                              << "CARRIER (or CAR) , CRUISER (or CRU), HYDROPLANE (or HYDRO or HYD) , DESTROYER (or DES), SUBMARINE (or SUB)"
                              << std::endl
                              << std::endl;

                    continue;
                }

                ship = field->removeUnit(unitType, sPosition);

                clearScreen();

                if (ship != nullptr)
                {
                    std::cout << "The " << ship->getShipName() << " that was at " << Field::string_to_Coordinate(sPosition) << " was "
                              << "successfully removed, Sir!" << std::endl
                              << std::endl;

                    general + unitType;

                    delete auxField;

                    auxField = new Field(*field);
                }
                else
                {
                    std::cout << "There is no " << unitType_to_string(unitType) << " at " << sPosition << ", Sir!" << std::endl
                              << std::endl;
                }
            }
            else
            {
                std::cin >> sDirection;

                std::transform(sDirection.begin(), sDirection.end(), sDirection.begin(), ::toupper);

                std::cin.seekg(0, std::ios::end);
                std::cin.clear();

                if (sDirection == "NORTH" || sDirection == "N")
                {
                    direction = ShipDirection::NORTH;
                }
                else if (sDirection == "EAST" || sDirection == "E")
                {
                    direction = ShipDirection::EAST;
                }
                else if (sDirection == "SOUTH" || sDirection == "S")
                {
                    direction = ShipDirection::SOUTH;
                }
                else if (sDirection == "WEST" || sDirection == "W")
                {
                    direction = ShipDirection::WEST;
                }
                else
                {
                    inputFailed = true;

                    clearScreen();

                    std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection
                              << std::endl
                              << std::endl
                              << "    These are the only possible directions :" << std::endl
                              << std::endl
                              << "NORTH (or N) , EAST (or E), SOUTH (or S) , WEST (or W)" << std::endl
                              << std::endl;

                    continue;
                }

                try
                {

                    if (ship != nullptr)
                    {
                        delete ship;
                    }

                    if (sShip == "CARRIER" || sShip == "CAR")
                    {
                        unitType = UnitType::CARRIER;
                    }
                    else if (sShip == "CRUISER" || sShip == "CRU")
                    {
                        unitType = UnitType::CRUISER;
                    }
                    else if (sShip == "HYDRO" || sShip == "HYDROPLANE" || sShip == "HYD")
                    {
                        unitType = UnitType::HYDROPLANE;
                    }
                    else if (sShip == "DESTROYER" || sShip == "DES")
                    {
                        unitType = UnitType::DESTROYER;
                    }
                    else if (sShip == "SUBMARINE" || sShip == "SUB")
                    {
                        unitType = UnitType::SUBMARINE;
                    }
                    else
                    {
                        inputFailed = true;

                        clearScreen();

                        std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " "
                                  << sDirection << std::endl
                                  << std::endl
                                  << "    You must address to these, and only these, kind of UNITS:" << std::endl
                                  << std::endl
                                  << "CARRIER (or CAR) , CRUISER (or CRU), HYDROPLANE (or HYDRO or HYD) , DESTROYER (or DES), SUBMARINE (or SUB)"
                                  << std::endl
                                  << std::endl;

                        continue;
                    }

                    ship = general.makeShip(unitType, sPosition, direction);

                    if (ship == nullptr)
                    {
                        inputFailed = true;

                        clearScreen();

                        std::cout << "Sir, there is no " << unitType << " left for manouver, Sir." << std::endl
                                  << std::endl;

                        continue;
                    }
                }
                catch (std::out_of_range &e)
                {
                    inputFailed = true;

                    clearScreen();

                    std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection
                              << std::endl
                              << e.what()
                              << std::endl;
                }
                catch (std::invalid_argument &e)
                {
                    inputFailed = true;

                    clearScreen();

                    std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection
                              << std::endl
                              << e.what()
                              << std::endl;
                }
                catch (std::exception &e)
                {
                    std::cout << "\n\nsomething baaaaaad.\n\n\t\t\taborting the game.";
                    exit(-1);
                }

                //TODO dont use clone, as the ownership of the UNIT can be given to the field.
                ShipAppendResult shipAppendResult = (*auxField << ship->clone());

                bool isYes = false;
                bool isYesOrNo;

                switch (shipAppendResult)
                {
                case ShipAppendResult::APPENDED:

                    clearScreen();

                    std::cout << "GENERAL " << general << ", " << ship->getShipName() << " was " << sCommand
                              << "D with success, Sir. " << std::endl
                              << std::endl;

                    std::cout << *auxField;

                    do
                    {
                        std::cout << std::endl
                                  << "Would you like to actually PLACE this " << ship->getShipName()
                                  << " there, Sir? (Yes/No)" << std::endl;

                        std::cin >> sCommand;

                        std::transform(sCommand.begin(), sCommand.end(), sCommand.begin(), ::toupper);

                        if (sCommand == "YES")
                        {
                            isYesOrNo = true;
                            isYes = true;
                        }
                        else if (sCommand == "NO")
                        {
                            isYesOrNo = true;
                            isYes = false;
                        }
                        else
                        {
                            isYesOrNo = false;
                            std::cout << std::endl
                                      << "Please, respond yes or no, Sir." << std::endl
                                      << std::endl;
                        }

                    } while (!isYesOrNo);

                    if (isYes)
                    {
                        delete field;
                        field = new Field(*auxField);

                        general - unitType;
                    }
                    else
                    {
                        auxField = new Field(*field);
                    }

                    clearScreen();

                    break;

                case ShipAppendResult::NOT_APPENDED_TOO_CLOSE:
                    std::cout << "GENERAL " << general << ", this " << ship->getShipName() << " can't be placed at "
                              << sPosition << std::endl
                              << "This is due to its proximity to other already placed UNITS, Sir." << std::endl
                              << "Please, reconsider your order, Sir." << std::endl
                              << std::endl;
                    inputFailed = true;
                    break;

                case ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS:
                    std::cout << "NOT_APPENDED_OUT_OF_BOUNDS" << std::endl;
                    std::cout << "GENERAL " << general << ", this " << ship->getShipName() << " can't be placed at "
                              << sPosition << std::endl
                              << "This is due to the limits of the battlefield, Sir." << std::endl
                              << "Please, reconsider your order, Sir." << std::endl
                              << std::endl;
                    inputFailed = true;
                    break;
                }
            }

        } while (inputFailed || (general.getSumRemaining() > 0));
    }
    else
    {
        Coordinate position(randomNumberGenerator(0, 13), randomNumberGenerator(0, 13));
        Ship *ship = nullptr;
        ShipAppendResult appendResult;
        std::stringstream ssScreen;
        std::string strShipDirection;

        Field *auxField;

        for (UnitType unitType = UnitType::CARRIER; unitType >= UnitType::SUBMARINE; unitType = UnitType(unitType - 1))
        {
            do
            {
                do
                {

                    ssScreen.str(std::string());

                    auxField = new Field(*field);

                    do
                    {
                        if (ship != nullptr)
                        {
                            delete ship;
                        }

                        position = Coordinate(randomNumberGenerator(0, 13), randomNumberGenerator(0, 13));

                        ship = general.makeShip(unitType, position,
                                                static_cast<ShipDirection>(randomNumberGenerator(0, 3)));

                        appendResult = *auxField << ship->clone();

                    } while (appendResult != ShipAppendResult::APPENDED);

                    switch (ship->getShipDirection())
                    {
                    case ShipDirection::NORTH:
                        strShipDirection = "NORTH";
                        break;
                    case ShipDirection::EAST:
                        strShipDirection = "EAST";
                        break;
                    case ShipDirection::SOUTH:
                        strShipDirection = "SOUTH";
                        break;
                    case ShipDirection::WEST:
                        strShipDirection = "WEST";
                        break;
                    }

                    ssScreen << "GENERAL " << general << " our Intelligence Agency recommended us" << std::endl
                             << "to place this " << ship->getShipName() << " in (" << ship->getRotationCenter() << " , " << strShipDirection
                             << ") as showed in the map bellow, Sir:" << std::endl
                             << std::endl
                             << "Would you like to follow their recommendation, Sir?" << std::endl;

                    ssScreen << *auxField;

                } while (getYesOrNo(ssScreen) == false);

                field = new Field(*auxField);

                general - unitType;

            } while (general.getRemaining(unitType) > 0);
        }
    }
}

int main()
{
    srand(time(NULL));

    system("CLS");

    std::cout << std::endl
              << std::endl
              << "___---***---||___   BATTLESHIP        ___||---***---___" << std::endl
              << "\\____._._.______/              GAME   \\______._._.____/" << std::endl
              << std::endl
              << std::endl;

    std::cout << "  You both are the GENERALs of the navy of your Countries and a  " << std::endl
              << "massive war between your countries is in course and you both must" << std::endl
              << "     to take action to defend your countries and your people     " << std::endl
              << std::endl
              << std::endl;

    //std::cout << "What is the name of the first GENERAL? (1st player)" << std::endl;

    General general1("Sanders", "Oregon");

    /*std::string general1;
    std::cin >> general1;

    std::cout << std::endl;

    std::cout << "What is the name of GENERAL " << general1 << "'s Country?" << std::endl;

    std::string country1;
    std::cin >> country1;
    std::cout << std::endl << std::endl;*/

    //std::cout << "What is the name of the second General? (2st player)" << std::endl;

    General general2("Roatford", "Mississipi");
    /*
    std::string general2;
    std::cin >> general2;

    std::cout << std::endl;

    std::cout << "What is the name of GENERAL " << general2 << "'s Country?" << std::endl;

    std::string country2;
    std::cin >> country2;
    std::cout << std::endl << std::endl;
*/
    clearScreen();

    std::stringstream ssScreen;

    ssScreen << std::endl
             << std::endl
             << "GENERAL " << general1 << " from " << general2.getCountry() << " and "
             << "GENERAL " << general2 << " from " << general2.getCountry() << ","
             << std::endl
             << std::endl
             << "Each of you have the following battleships available" << std::endl
             << "    PLEASE, when asked, enter \"ACK\" to confirm" << std::endl
             << "acknowledgement before you proceed to the next steps" << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "The great CARRIER" << std::endl
             << std::endl
             << "___---***---__--^-||______________________________" << std::endl
             << "\\         1____________ _____1                __/    Only ONE available" << std::endl
             << " \\____._._.____________________________________/    Size: 5 cells" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "The unbeatable CRUISERS" << std::endl
             << std::endl
             << "___-_-__^^^__ooOO00Oo-||__%-----%====\\__    TWO available" << std::endl
             << "\\____._._._____________________________/    Size: 4 cells" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "The fastest DESTROYERS" << std::endl
             << std::endl
             << "___---***---||______                         THREE available" << std::endl
             << "\\_._.,,____________/                        Size: 2 cells" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "The untraceable SUBMARINES" << std::endl
             << std::endl
             << " _/-\\____                                   FOUR available" << std::endl
             << "(________)                                   Size: 1 cell" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "The highest HYDRO PLANES" << std::endl
             << std::endl
             << "           __" << std::endl
             << "           \\ \\" << std::endl
             << "         _  \\ \\" << std::endl
             << "    ____/ \\_/  \\_                           FIVE available" << std::endl
             << " .-'  ,---,    __|_                           Size: 3 cell" << std::endl
             << " '-.__`---`_    _|" << std::endl
             << "        \\_/ \\  /" << std::endl
             << "            / /" << std::endl
             << "           /_/" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    Field *auxField(new Field());

    ssScreen << "        Here is presented to you the battle field" << std::endl
             << "This is a 14 x 14 battle field, for each one of you, GENERALS" << std::endl
             << std::endl

             << *auxField << std::endl
             << std::endl

             << "In this field, as already advised, you may place:" << std::endl
             << std::endl
             << std::setw(6) << "ONE " << std::setw(13) << "CARRIER"
             << "\t5 cells" << std::endl
             << std::setw(6) << "TWO " << std::setw(13) << "CRUISERS"
             << "\t4 cells" << std::endl
             << std::setw(6) << "THREE " << std::setw(13) << "HYDRO PLANES"
             << "\t3 cells" << std::endl
             << std::setw(6) << "FOUR " << std::setw(13) << "DESTROYERS"
             << "\t2 cells" << std::endl
             << std::setw(6) << "FIVE " << std::setw(13) << "SUBMARINES"
             << "\t1 cells" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::string password1;
    std::string password2;

    std::cout << "In order to assure safety of the commanded UNITS of" << std::endl
              << "   one GENERAL with respect to the other, both of" << std::endl
              << "                you need to create a" << std::endl
              << std::endl
              << "                      PASSWORD" << std::endl
              << std::endl
              << "This password will be used to prevent leakage of" << std::endl
              << "   one GENERAL's battle tactics to the other  " << std::endl
              << std::endl
              << "GENERAL " << general1 << " first. Please enter your password and press ENTER." << std::endl
              << std::endl
              << "GENERAL " << general1 << "  password: " << std::endl;

    std::cin >> password1;

    ssScreen.str(std::string());

    ssScreen << "Ok. GENERAL " << general1 << ", please acknowledge to" << std::endl
             << "store your password and destroy this password message" << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::cout << std::endl
              << "Now, GENERAL " << general2 << ", please enter your password." << std::endl
              << std::endl
              << "GENERAL " << general2 << " password: " << std::endl;
    std::cin >> password2;

    ssScreen.str(std::string());

    ssScreen << "Ok. GENERAL " << general2 << ", please acknowledge to" << std::endl
             << "store your password and destroy this password message" << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << " Great. Now both of you have passwords to protect your tactics!" << std::endl
             << "      Only your password will unlock your TACTICS SCREEN" << std::endl
             << std::endl
             << "        NEVER ALLOW YOUR ENEMY TO POSSES YOUR PASSWORD!" << std::endl
             << std::endl
             << "Otherwise, the position of your UNITS will be known and therefore" << std::endl
             << "             WILL BE MERCILESS ATTACKED BY THE ENEMY" << std::endl
             << std::endl
             << std::endl;

    //getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << " Now, the next step is to place your UNITS in the field" << std::endl
             << std::endl
             << "           GENERAL " << general2 << " first." << std::endl
             << "Please enter your password to unlock your TACTICS SCREEN, Sir" << std::endl
             << std::endl
             << std::endl;

    confirmPassword(ssScreen, password2);

    ssScreen.str(std::string());
    clearScreen();

    *auxField << new Destroyer("D13", ShipDirection::WEST);
    *auxField << new HydroPlane("B5", ShipDirection::SOUTH);

    ssScreen << "It's time to make your path to the victory, GENERAL " << general2 << "!" << std::endl
             << "         Here is the field for your UNITS, Sir" << std::endl
             << "   You need to specify the central coordinates of" << std::endl
             << "your UNITS and the direction they will be pointed to, Sir" << std::endl
             << std::endl
             << "You must command your ship with a column line instruction" << std::endl
             << "E.g.: a DESTROYER in D13 WEST and a HYDRO PLANE B5 SOUTH" << std::endl
             << "              will be placed as follows:" << std::endl
             << std::endl
             << *auxField << std::endl
             << std::endl
             << "Now, GENERAL " << general2 << ", you will send position" << std::endl
             << "             instructions to your UNITS." << std::endl
             << std::endl
             << "Give instructions like (note that commands ARE NOT case sensitive):" << std::endl
             << std::endl
             << std::endl
             << "To PLACE on the FIELD:             place carrier b5 west" << std::endl
             << "                                   place Destroyer n10 east" << std::endl
             << "                                   place submarine D8 south" << std::endl
             << std::endl
             << std::endl
             << "To REMOVE position on the FIELD:   remove carrier b5" << std::endl
             << "                                   remove DESTROYER n10" << std::endl
             << "                                   remove submarine D8" << std::endl;

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    Field *field1 = new Field();

    ssScreen << "GENERAL " << general1 << ", our Intelligence Agency is totally available" << std::endl
             << "to give you all their support with respect to place our units in the" << std::endl
             << "battlefield, Sir." << std::endl
             << std::endl
             << "Would you like to have access to their recommendations, Sir?" << std::endl
             << std::endl;

    if (getYesOrNo(ssScreen))
    {
        placeUnits(general1, field1, true);

        std::cout << *field1;
    }
    else
    {
        ssScreen.str(std::string());

        placeUnits(general1, field1, false);
    }

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "             GENERAL " << general1 << "'s turn." << std::endl
             << "Please enter your password to unlock your TACTICS SCREEN, Sir" << std::endl
             << std::endl
             << std::endl;

    confirmPassword(ssScreen, password1);

    ssScreen.str(std::string());
    clearScreen();

    ssScreen << "It's time to make your path to the victory, GENERAL " << general1 << "!" << std::endl
             << "         Here is the field for your UNITS." << std::endl
             << "   You need to specify the central coordinates of" << std::endl
             << "your UNITS and the direction they will be pointed to." << std::endl
             << std::endl
             << "You must command your ship with a column line instruction" << std::endl
             << "E.g.: a DESTROYER in D13 WEST and a HYDRO PLANE B5 SOUTH" << std::endl
             << "              will be placed as follows:" << std::endl
             << std::endl
             << *auxField << std::endl
             << std::endl
             << "Now, GENERAL " << general1 << ", you will send position" << std::endl
             << "             instructions to your UNITS." << std::endl
             << std::endl
             << "Give instructions like (note that commands ARE NOT case sensitive):" << std::endl
             << std::endl
             << std::endl
             << "To PLACE on the FIELD:             place carrier b5 west" << std::endl
             << "                                   place Destroyer n10 east" << std::endl
             << "                                   place submarine D8 south" << std::endl
             << std::endl
             << std::endl
             << "To REMOVE position on the FIELD:   remove carrier b5" << std::endl
             << "                                   remove DESTROYER n10" << std::endl
             << "                                   remove submarine D8" << std::endl;

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    Field *field2 = new Field();

    ssScreen << "GENERAL " << general1 << ", our Intelligence Agency is totally available" << std::endl
             << "to give you all their support with respect to place our units in the" << std::endl
             << "battlefield, Sir." << std::endl
             << std::endl
             << "Would you like to have access to their recommendations, Sir?" << std::endl
             << std::endl;

    if (getYesOrNo(ssScreen))
    {
        placeUnits(general2, field2, true);

        std::cout << *field2;
    }
    else
    {
        placeUnits(general2, field2, false);
    }

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::vector<Ship *> shipVector;

    for (Ship *s : shipVector)
    {
        std::cout << s->getShipName() << " : " << s->getRotationCenter() << "\t";
        ShipAppendResult result = *auxField << s;
        switch (result)
        {
        case ShipAppendResult::APPENDED:
            std::cout << "APPENDED" << std::endl;
            break;
        case ShipAppendResult::NOT_APPENDED_TOO_CLOSE:
            std::cout << "NOT_APPENDED_TOO_CLOSE" << std::endl;
            break;
        case ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS:
            std::cout << "NOT_APPENDED_OUT_OF_BOUNDS" << std::endl;
            break;
        }
        std::cout << *auxField << std::endl;
    }

    return 0;
}