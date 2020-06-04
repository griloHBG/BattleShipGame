#include "aux/Aux.h"

int main()
{
    srand(time(NULL));

    system("clear");

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

    Board *auxBoard(new Board());

    ssScreen << "        Here is presented to you the battle field" << std::endl
             << "This is a 14 x 14 battle field, for each one of you, GENERALS" << std::endl
             << std::endl

             << *auxBoard << std::endl
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

    *auxBoard << new Destroyer("D13", ShipDirection::WEST);
    *auxBoard << new HydroPlane("B5", ShipDirection::SOUTH);

    ssScreen << "It's time to make your path to the victory, GENERAL " << general2 << "!" << std::endl
             << "         Here is the field for your UNITS, Sir" << std::endl
             << "   You need to specify the central coordinates of" << std::endl
             << "your UNITS and the direction they will be pointed to, Sir" << std::endl
             << std::endl
             << "You must command your ship with a column line instruction" << std::endl
             << "E.g.: a DESTROYER in D13 WEST and a HYDRO PLANE B5 SOUTH" << std::endl
             << "              will be placed as follows:" << std::endl
             << std::endl
             << *auxBoard << std::endl
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

    Board *board1 = new Board();

    ssScreen << "GENERAL " << general1 << ", our Intelligence Agency is totally available" << std::endl
             << "to give you all their support with respect to place our units in the" << std::endl
             << "battlefield, Sir." << std::endl
             << std::endl
             << "Would you like to have access to their recommendations, Sir?" << std::endl
             << std::endl;

    if (getYesOrNo(ssScreen))
    {
        placeUnits(general1, board1, true);

        std::cout << *board1;
    }
    else
    {
        ssScreen.str(std::string());

        placeUnits(general1, board1, false);
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
             << *auxBoard << std::endl
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

    Board *board2 = new Board();

    ssScreen << "GENERAL " << general1 << ", our Intelligence Agency is totally available" << std::endl
             << "to give you all their support with respect to place our units in the" << std::endl
             << "battlefield, Sir." << std::endl
             << std::endl
             << "Would you like to have access to their recommendations, Sir?" << std::endl
             << std::endl;

    if (getYesOrNo(ssScreen))
    {
        placeUnits(general2, board2, true);

        std::cout << *board2;
    }
    else
    {
        placeUnits(general2, board2, false);
    }

    getAcknowledgement(ssScreen);

    ssScreen.str(std::string());
    clearScreen();

    std::vector<Ship *> shipVector;

    for (Ship *s : shipVector)
    {
        std::cout << s->getShipName() << " : " << s->getRotationCenter() << "\t";
        ShipAppendResult result = *auxBoard << s;
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
        std::cout << *auxBoard << std::endl;
    }

    return 0;
}

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
