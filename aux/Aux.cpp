#include "Aux.h"

// Generating a random number.
// uint8_t is a type variable that indicates precisely that it is an unsigned single-byte (8 bits) integer. Number between 0 and 255
// Preciseness never hurt anyone :)
int randomNumberGenerator(uint8_t low, uint8_t high)
{
  int random_int = (rand() % (high - low)) + low;

  return random_int;
}

// Function to acknowledge some message
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

void confirmPassword(std::stringstream &ssScreen, const std::string &password)
{
  initscr();
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

void placeUnits(General &general, Board *board, bool doRandomizeUNITS)
{
  if (!doRandomizeUNITS)
  {
    bool inputFailed;
    bool cantUseUnit;
    CommandType command;

    std::string sCommand, sShip, sPosition, sDirection;

    Board *auxBoard = new Board();

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
                << *auxBoard << std::endl
                << std::endl
                << std::endl
                << "To PLACE on the Board:             place carrier b5 west" << std::endl
                << "                                   place Destroyer n10 east" << std::endl
                << "                                   place submarine D8 south" << std::endl
                << std::endl
                << std::endl
                << "To REMOVE position on the Board:   remove carrier b5" << std::endl
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

        ship = board->removeUnit(unitType, sPosition);

        clearScreen();

        if (ship != nullptr)
        {
          std::cout << "The " << ship->getShipName() << " that was at " << Board::string_to_Coordinate(sPosition) << " was "
                    << "successfully removed, Sir!" << std::endl
                    << std::endl;

          general + unitType;

          delete auxBoard;

          auxBoard = new Board(*board);
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

        //TODO dont use clone, as the ownership of the UNIT can be given to the Board.
        ShipAppendResult shipAppendResult = (*auxBoard << ship->clone());

        bool isYes = false;
        bool isYesOrNo;

        switch (shipAppendResult)
        {
        case ShipAppendResult::APPENDED:

          clearScreen();

          std::cout << "GENERAL " << general << ", " << ship->getShipName() << " was " << sCommand
                    << "D with success, Sir. " << std::endl
                    << std::endl;

          std::cout << *auxBoard;

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
            delete board;
            board = new Board(*auxBoard);

            general - unitType;
          }
          else
          {
            auxBoard = new Board(*board);
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

    Board *auxBoard;

    for (UnitType unitType = UnitType::CARRIER; unitType >= UnitType::SUBMARINE; unitType = UnitType(unitType - 1))
    {
      do
      {
        do
        {

          ssScreen.str(std::string());

          auxBoard = new Board(*board);

          do
          {
            if (ship != nullptr)
            {
              delete ship;
            }

            position = Coordinate(randomNumberGenerator(0, 13), randomNumberGenerator(0, 13));

            ship = general.makeShip(unitType, position,
                                    static_cast<ShipDirection>(randomNumberGenerator(0, 3)));

            appendResult = *auxBoard << ship->clone();

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

          ssScreen << *auxBoard;

        } while (getYesOrNo(ssScreen) == false);

        board = new Board(*auxBoard);

        general - unitType;

      } while (general.getRemaining(unitType) > 0);
    }
  }
}