#include <iostream> //cout, endl
#include "Field.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Carrier.h"
#include "HydroPlane.h"
#include "Cruiser.h"
#include <conio.h> //getch
#include <algorithm> //transform
#include <memory> // make_shared
#include "ShipType.h"

#define clearScreen() system("CLS")

enum CommandType
{
    TEST,
    PLACE,
    REMOVE,
    INVALID
};

void getAcknowledgement(std::stringstream& ssScreen)
{
    std::string playerInput;
    bool firstTime = true;

    do
    {
        if(firstTime)
        {
            firstTime = false;
        }
        else
        {
            std::cout << "Please, acknowledge the following message:" << std::endl << std::endl;
        }

        std::cout << std::endl;
        std::cout << ssScreen.str();
        std::cout << std::endl;
        std::cout << "ACKNOWLEDGEMENT: " << std::endl;
        std::cin >> playerInput;

        clearScreen();

    }while(playerInput != "ack" && playerInput != "ACK");
}

void confirmPassword(std::stringstream& ssScreen, const std::string& password)
{
    std::string playerInput;
    bool firstTime = true;

    do
    {
        if(firstTime)
        {
            firstTime = false;
        }
        else
        {
            std::cout << "PASSWORD INCORRECT! Please enter your password." << std::endl << std::endl;
        }

        std::cout << ssScreen.str();
        std::cout << std::endl;
        std::cout << "PASSWORD: " << std::endl;
        std::cin >> playerInput;

        clearScreen();

    }while(playerInput != password);

    std::cout << "PASSWORD CORRECT!" << std::endl;
    std::cout << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    getch();

}

int main()
{

    system("CLS");

    std::cout   << std::endl << std::endl
                << "___---***---||___   BATTLESHIP        ___||---***---___"    << std::endl
                << "\\____._._.______/              GAME   \\______._._.____/"  << std::endl
                << std::endl << std::endl;

    std::cout << "  You both are the GENERALs of the navy of your Countries and a  " << std::endl
              << "massive war between your countries is in course and you both must" << std::endl
              << "     to take action to defend your countries and your people     " << std::endl
              << std::endl << std::endl;

    std::cout << "What is the name of the first GENERAL? (1st player)" << std::endl;

    std::string general1;
    std::cin >> general1;

    std::cout << std::endl;

    std::cout << "What is the name of GENERAL " << general1 << "'s Country?" << std::endl;

    std::string country1;
    std::cin >> country1;
    std::cout << std::endl << std::endl;

    std::cout << "What is the name of the second General? (2st player)" << std::endl;

    std::string general2;
    std::cin >> general2;

    std::cout << std::endl;

    std::cout << "What is the name of GENERAL " << general2 << "'s Country?" << std::endl;

    std::string country2;
    std::cin >> country2;
    std::cout << std::endl << std::endl;

    clearScreen();

    std::stringstream ssScreen;

    ssScreen << std::endl << std::endl
             << "GENERAL " << general1 << " from " << country1 << " and "
             << "GENERAL " << general2 << " from " << country2 << ","
                                                                            << std::endl
                                                                            << std::endl
             << "Each of you have the following battleships available"      << std::endl
             << "    PLEASE, when asked, enter \"ACK\" to confirm"          << std::endl
             << "acknowledgement before you proceed to the next steps"      << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << "The great CARRIER"                                                         << std::endl
                                                                                                << std::endl
                 << "___---***---__--^-||______________________________"                        << std::endl
                 << "\\         1____________ _____1                __/    Only ONE available"  << std::endl
                 << " \\____._._.____________________________________/    Size: 5 cells"        << std::endl
                                                                                                << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << "The unbeatable CRUISERS"                                                   << std::endl
                                                                                                << std::endl
                 << "___-_-__^^^__ooOO00Oo-||__%-----%====\\__    TWO available"                << std::endl
                 << "\\____._._._____________________________/    Size: 4 cells"                << std::endl
                                                                                                << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << "The fastest DESTROYERS"                                                    << std::endl
                                                                                                << std::endl
                 << "___---***---||______                         THREE available"              << std::endl
                 << "\\_._.,,____________/                        Size: 2 cells"                << std::endl
                                                                                                << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << "The untraceable SUBMARINES"                                                << std::endl
                                                                                                << std::endl
                 << " _/-\\____                                   FOUR available"               << std::endl
                 << "(________)                                   Size: 1 cell"                 << std::endl
                                                                                                << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << "The highest HYDRO PLANES"                                                  << std::endl
                                                                                                << std::endl
                 << "           __"                                                             << std::endl
                 << "           \\ \\"                                                          << std::endl
                 << "         _  \\ \\"                                                         << std::endl
                 << "    ____/ \\_/  \\_                           FIVE available"              << std::endl
                 << " .-'  ,---,    __|_                           Size: 3 cell"                << std::endl
                 << " '-.__`---`_    _|"                                                        << std::endl
                 << "        \\_/ \\  /"                                                        << std::endl
                 << "            / /"                                                           << std::endl
                 << "           /_/"                                                            << std::endl
                                                                                                << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    Field auxField;

        ssScreen << "        Here is presented to you the battle field"                             << std::endl
                 << "This is a 14 x 14 battle field, for each one of you, GENERALS"                 << std::endl
                                                                                                    << std::endl

                 << auxField                                                                        << std::endl
                                                                                                    << std::endl

                 << "In this field, as already advised, you may place:"                             << std::endl
                                                                                                    << std::endl
                 << std::setw(6) << "ONE "      << std::setw(13) << "CARRIER"      << "\t5 cells"   << std::endl
                 << std::setw(6) << "TWO "      << std::setw(13) << "CRUISERS"     << "\t4 cells"   << std::endl
                 << std::setw(6) << "THREE "    << std::setw(13) << "HYDRO PLANES" << "\t3 cells"   << std::endl
                 << std::setw(6) << "FOUR "     << std::setw(13) << "DESTROYERS"   << "\t2 cells"   << std::endl
                 << std::setw(6) << "FIVE "     << std::setw(13) << "SUBMARINES"   << "\t1 cells"   << std::endl
                                                                                                    << std::endl
                                                                                                    << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::string password1;
    std::string password2;

        std::cout << "In order to assure safety of the commanded UNITS of"                          << std::endl
                  << "   one GENERAL with respect to the other, both of"                            << std::endl
                  << "                you need to create a"                                         << std::endl
                                                                                                    << std::endl
                  << "                      PASSWORD"                                               << std::endl
                                                                                                    << std::endl
                  << "This password will be used to prevent leakage of"                             << std::endl
                  << "   one GENERAL's battle tactics to the other  "                               << std::endl
                                                                                                    << std::endl
                  << "GENERAL " << general1 << " first. Please enter your password and press ENTER."<< std::endl
                                                                                                    << std::endl
                  << "GENERAL " << general1 << "  password: "                                       << std::endl;

        std::cin >> password1;

    ssScreen.str(std::string());

        ssScreen << "Ok. GENERAL " << general1 << ", please acknowledge to" << std::endl
                 << "store your password and destroy this password message" << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        std::cout << std::endl
                    << "Now, GENERAL " << general2 << ", please enter your password."   << std::endl
                                                                                        << std::endl
                    << "GENERAL " << general2 << " password: "                          << std::endl;
        std::cin >> password2;

    ssScreen.str(std::string());

        ssScreen << "Ok. GENERAL " << general2 << ", please acknowledge to" << std::endl
                 << "store your password and destroy this password message" << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << " Great. Now both of you have passwords to protect your tactics!"   << std::endl
                 << "      Only your password will unlock your TACTICS SCREEN"          << std::endl
                                                                                        << std::endl
                 << "        NEVER ALLOW YOUR ENEMY TO POSSES YOUR PASSWORD!"           << std::endl
                                                                                        << std::endl
                 << "Otherwise, the position of your UNITS will be known and therefore" << std::endl
                 << "             WILL BE MERCILESS ATTACKED BY THE ENEMY"              << std::endl
                                                                                        << std::endl << std::endl;

    //getackknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

        ssScreen << " Now, the next step is to place your UNITS in the field"   << std::endl
                                                                                << std::endl
                 << "           GENERAL " << general2 << " first."              << std::endl
                 << "Please enter your password to unlock your TACTICS SCREEN"  << std::endl
                                                                                << std::endl << std::endl;

    confirmPassword(ssScreen, password2);

    ssScreen.str(std::string());
    clearScreen();

    auxField = Field();
    auxField << new Destroyer("D13", ShipDirection::WEST);
    auxField << new HydroPlane("B5", ShipDirection::SOUTH);

        ssScreen << "It's time to make your path to the victory, GENERAL " << general2 << "!"   << std::endl
                 << "         Here is the field for your UNITS."                                << std::endl
                 << "   You need to specify the central coordinates of"                         << std::endl
                 << "your UNITS and the direction they will be pointed to."                     << std::endl
                                                                                                << std::endl
                 << "You must command your ship with a column line instruction"                 << std::endl
                 << "E.g.: a DESTROYER in D13 WEST and a HYDRO PLANE B5 SOUTH"                  << std::endl
                 << "              will be placed as follows:"                                  << std::endl
                                                                                                << std::endl
                 << auxField                                                                    << std::endl
                                                                                                << std::endl
                 << "Now, GENERAL " << general2 << ", you will send position"                   << std::endl
                 << "             instructions to your UNITS."                                  << std::endl
                                                                                                << std::endl
                 << "Give instructions like (note that commands ARE NOT case sensitive):"       << std::endl
                                                                                                << std::endl
                                                                                                << std::endl
                 << "To PLACE on the FIELD:             place carrier b5 west"                  << std::endl
                 << "                                   place Destroyer n10 east"               << std::endl
                 << "                                   place submarine D8 south"               << std::endl
                                                                                                << std::endl
                                                                                                << std::endl
                 << "To TEST position on the FIELD:     test carrier b5 west"                   << std::endl
                 << "                                   test DESTROYER n10 east"                << std::endl
                 << "                                   test submarine D8 west"                 << std::endl
                                                                                                << std::endl
                                                                                                << std::endl
                 << "To REMOVE position on the FIELD:   remove carrier b5"                      << std::endl
                 << "                                   remove DESTROYER n10"                   << std::endl
                 << "                                   remove submarine D8"                    << std::endl;

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    uint8_t remainingCarriers       = 1;
    uint8_t remainingCruisers       = 2;
    uint8_t remainingHydroPlanes    = 3;
    uint8_t remainingDestroyers     = 4;
    uint8_t remainingSubmarines     = 5;

    bool cantUseUnit;

    auxField = Field();

    Field* field1 = new Field();
    Field* field2 = new Field();

    std::string sShip;
    std::string sPosition;
    std::string sDirection;
    std::string sCommand;

    bool inputFailed;

    Ship* ship = nullptr;
    ShipDirection direction;
    CommandType command = CommandType::INVALID;

    UnitType unitType;

    do
    {
        inputFailed = false;
        cantUseUnit = false;
        command = CommandType::INVALID;

        std::cout<< "GENERAL " << general2 << ", these are UNITS you still have available, Sir:"                << std::endl
                                                                                                                << std::endl
                << std::setw(6) << static_cast<int>(remainingCarriers)    << std::setw(13) << "CARRIER"      << "\t( 5 cells )"   << std::endl
                << std::setw(6) << static_cast<int>(remainingCruisers)    << std::setw(13) << "CRUISERS"     << "\t( 4 cells )"   << std::endl
                << std::setw(6) << static_cast<int>(remainingHydroPlanes) << std::setw(13) << "HYDRO PLANES" << "\t( 3 cells )"   << std::endl
                << std::setw(6) << static_cast<int>(remainingDestroyers)  << std::setw(13) << "DESTROYERS"   << "\t( 2 cells )"   << std::endl
                << std::setw(6) << static_cast<int>(remainingSubmarines)  << std::setw(13) << "SUBMARINES"   << "\t( 1 cells )"   << std::endl
                                                                                                                << std::endl
                << auxField                                                                                     << std::endl
                                                                                                                << std::endl
                                                                                                                << std::endl;



                std::cin >> sCommand >> sShip >> sPosition >> sDirection;

                std::cin.seekg(0,std::ios::end);
                std::cin.clear();

                std::transform(sCommand.begin(), sCommand.end(), sCommand.begin(), ::toupper);
                std::transform(sPosition.begin(), sPosition.end(), sPosition.begin(), ::toupper);
                std::transform(sShip.begin(), sShip.end(), sShip.begin(), ::toupper);
                std::transform(sDirection.begin(), sDirection.end(), sDirection.begin(), ::toupper);

                if (sCommand == "TEST")
                {
                    inputFailed = false;
                    command = CommandType::TEST;
                }
                else if( sCommand == "PLACE")
                {
                    inputFailed = false;
                    command = CommandType::PLACE;
                }
                else if(sCommand == "REMOVE")
                {
                    inputFailed = false;
                    command = CommandType::REMOVE;
                }
                else
                {
                    inputFailed = true;
                    command = CommandType::INVALID;

                    clearScreen();

                    std::cout   << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection   << std::endl
                                << std::endl
                                << "    You must only use one of these command instructions:"   << std::endl
                                << "                 TEST  OR  PLACE  OR REMOVE"                << std::endl
                                << std::endl;
                }

                if(command == CommandType::REMOVE) {

                }
                else {

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

                        std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection << std::endl
                                  << std::endl
                                  << "    These are the only possible directions :" << std::endl
                                  << std::endl
                                  << "NORTH (or N) , EAST (or E), SOUTH (or S) , WEST (or W)" << std::endl
                                  << std::endl;

                        continue;
                    }

                    try{

                        if(ship != nullptr)
                        {
                            delete ship;
                        }

                        if (sShip == "CARRIER" || sShip == "CAR")
                        {
                            unitType = UnitType::CARRIER;
                            ship = new Carrier(sPosition, direction);

                            if(remainingCarriers == 0)
                            {
                                cantUseUnit = true;
                            }
                        }
                        else if (sShip == "CRUISER" || sShip == "CRU")
                        {
                            unitType = UnitType::CRUISER;
                            ship = new Cruiser(sPosition, direction);

                            if(remainingCruisers == 0)
                            {
                                cantUseUnit = true;
                            }
                        }
                        else if (sShip == "HYDRO" || sShip == "HYDROPLPANE" || sShip == "HYD")
                        {
                            unitType = UnitType::HYDROPLANE;
                            ship = new HydroPlane(sPosition, direction);

                            if(remainingHydroPlanes == 0)
                            {
                                cantUseUnit = true;
                            }
                        }
                        else if (sShip == "DESTROYER" || sShip == "DES")
                        {
                            unitType = UnitType::DESTROYER;
                            ship = new Destroyer(sPosition, direction);

                            if(remainingDestroyers == 0)
                            {
                                cantUseUnit = true;
                            }
                        }
                        else if (sShip == "SUBMARINE" || sShip == "SUB")
                        {
                            unitType = UnitType::SUBMARINE;
                            ship = new Submarine(sPosition);

                            if(remainingSubmarines == 0)
                            {
                                cantUseUnit = true;
                            }
                        }
                        else
                        {
                            inputFailed = true;

                            clearScreen();

                            std::cout << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection  << std::endl
                                                                                                                << std::endl
                                      << "    You must to address these, and only these, kind of UNITS:"        << std::endl
                                                                                                                << std::endl
                                      << "CARRIER (or CAR) , CRUISER (or CRU), HYDROPLANE (or HYDRO or HYD) , DESTROYER (or DES), SUBMARINE (or SUB)"    << std::endl
                                                                                                                << std::endl;
                        }

                        if(cantUseUnit)
                        {
                            inputFailed = true;

                            clearScreen();

                            std::cout << "Sir, there is no " << ship->getShipName() << " left for manouver, Sir."   << std::endl
                                                                                                                    << std::endl;
                        }
                    }
                    catch(std::out_of_range& e)
                    {
                        inputFailed = true;

                        clearScreen();

                        std::cout   << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection << std::endl
                                    << e.what()
                                    << std::endl;
                    }
                    catch(std::invalid_argument& e)
                    {
                        inputFailed = true;

                        clearScreen();

                        std::cout   << "You entered: " << sCommand << " " << sShip << " " << sPosition << " " << sDirection << std::endl
                                    << e.what()
                                    << std::endl;
                    }
                    catch(std::exception& e)
                    {
                        std::cout << "\n\nsomething baaaaaad.\n\n\t\t\taborting the game.";
                        exit(-1);
                    }

                    ShipAppendResult shipAppendResult = (auxField << ship->clone());

                    bool isYes = false;
                    bool isYesOrNo;

                    switch (shipAppendResult)
                    {
                        case ShipAppendResult::APPENDED:

                            std::cout << "GENERAL "<< general2 << ", " << ship->getShipName() << " was " << sCommand << "D with success, Sir. ";
                            std::cout << "Press any key to access the result." << std::endl;
                            getch();

                            clearScreen();

                            std::cout << auxField;

                            do
                            {
                                    std::cout   << std::endl
                                            << "Would you like to actually PLACE this " << ship->getShipName() << " there, Sir? (Yes/No)" << std::endl;

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
                                              << "Please, respond yes or no, Sir."  << std::endl
                                                                                    << std::endl;
                                }

                            }while( !isYesOrNo );

                            if(isYes)
                            {
                                delete field2;
                                field2 = new Field(auxField);

                                switch(unitType)
                                {
                                    case UnitType::CARRIER:
                                        remainingCarriers--;
                                        break;
                                    case UnitType::CRUISER:
                                        remainingCruisers--;
                                        break;
                                    case UnitType::HYDROPLANE:
                                        remainingHydroPlanes--;
                                        break;
                                    case UnitType::DESTROYER:
                                        remainingDestroyers--;
                                        break;
                                    case UnitType::SUBMARINE:
                                        remainingSubmarines--;
                                        break;
                                }
                            }
                            else
                            {
                                auxField = Field(*field2);
                            }

                            clearScreen();

                            break;

                        case ShipAppendResult::NOT_APPENDED_TOO_CLOSE:
                            std::cout   << "GENERAL " << general2 << ", this " << ship->getShipName() << " can't be placed at " << sPosition   << std::endl
                                        << "This is due to its proximity to other already placed UNITS, Sir."               << std::endl
                                        << "Please, reconsider your order, Sir."                                            << std::endl
                                                                                                                            << std::endl;
                            inputFailed = true;
                            break;

                        case ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS:
                            std::cout << "NOT_APPENDED_OUT_OF_BOUNDS" << std::endl;
                            std::cout   << "GENERAL " << general2 << ", this " << ship->getShipName() << " can't be placed at " << sPosition   << std::endl
                                        << "This is due to the limits of the battlefield, Sir."                             << std::endl
                                        << "Please, reconsider your order, Sir."                                            << std::endl
                                                                                                                            << std::endl;
                            inputFailed = true;
                            break;
                    }
                }

     }while(inputFailed || ((remainingCarriers + remainingCruisers + remainingHydroPlanes + remainingDestroyers + remainingSubmarines) > 0));

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::vector<Ship*> shipVector;

    for(Ship* s : shipVector)
    {
        std::cout << s->getShipName() << " : " << s->getRotationCenter() << "\t";
        ShipAppendResult result = auxField << s;
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
        std::cout << auxField << std::endl;
    }

    return 0;
}