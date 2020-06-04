/*
 * Board.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#include "Board.h"

#define W ' '

Board::Board()
    : m_grid{{W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W}}
{
}

Board::~Board() = default;

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    return out << board.toString();
}

ShipAppendResult Board::operator<<(Ship *ship)
{
    ShipAppendResult result = ShipAppendResult::APPENDED;

    for (auto fieldShip : this->m_ships)
    {
        int a = *fieldShip - *ship;
        if (a < 2)
        {
            result = ShipAppendResult::NOT_APPENDED_TOO_CLOSE;
            //std::cout << "Cada embarcação precisa ficar a, pelo menos, uma fila de célula de distância de outra embarcação\n";
        }
    }

    if (result == ShipAppendResult::APPENDED)
    {
        for (auto cell : ship->getCells())
        {
            try
            {
                this->at(cell.at(ROW), cell.at(COL));
            }
            catch (std::out_of_range &e)
            {
                result = ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS;
                break;
            }
        }

        if (result != ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS)
        {
            this->m_ships.push_back(ship);

            for (auto cell : ship->getCells())
            {
                this->at(cell.at(ROW), cell.at(COL), ship->getSymbol());
            }
        }
    }

    return result;
}

char Board::at(const uint8_t &row, const uint8_t &col) const
{
    try
    {
        boundCheck(row, col);
    }
    catch (std::out_of_range &e)
    {
        throw e;
    }

    return m_grid.at(row * ROWS + col);
}

std::string Board::toString() const
{
    std::stringstream result;

    result << "  |A|B|C|D|E|F|G|H|I|J|K|L|M|N|  " << std::endl;
    result << "--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--" << std::endl;

    bool toggle = true;

    for (int r = 0; r < 2 * ROWS - 1; r++)
    {
        if (r % 2 == 0)
        {
            result << std::setw(2) << (r + 1) / 2 << '|';

            for (int c = 0; c < COLS; c++)
            {
                result << this->at(r / 2, c) << '|';
            }

            result << (r + 1) / 2;

            result << std::endl;
        }
        else
        {
            result << "--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--" << std::endl;
        }
    }

    result << "--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--" << std::endl;
    result << "  |A|B|C|D|E|F|G|H|I|J|K|L|M|N| " << std::endl;

    return result.str();
}

void Board::at(const uint8_t &row, const uint8_t &col, const uint8_t &value)
{

    try
    {
        boundCheck(row, col);
    }
    catch (std::out_of_range &e)
    {
        throw e;
    }

    m_grid.at(row * ROWS + col) = value;
}

void Board::boundCheck(const uint8_t &row, const uint8_t &col) const
{
    try
    {
        if (row < 0)
        {
            throw std::out_of_range("Row cant be negative");
        }

        if (col < 0)
        {
            throw std::out_of_range("Col cant be negative");
        }

        if (row >= ROWS)
        {
            throw std::out_of_range("Row cant be greater than " + std::to_string(ROWS));
        }

        if (col >= COLS)
        {
            throw std::out_of_range("Col cant be greater than " + std::to_string(COLS));
        }
    }
    catch (std::out_of_range &e)
    {
        throw e;
    }
}

Ship *Board::removeUnit(const UnitType unitType, const std::string &sPosition)
{
    Ship *result = nullptr;

    Coordinate position = string_to_Coordinate(sPosition);

    try
    {
        at(position.at(ROW), position.at(COL));
    }
    catch (std::out_of_range e)
    {
        result = nullptr;
    }

    auto shipIter = m_ships.begin();

    while (shipIter != m_ships.end())
    {
        if ((*shipIter)->getUnitType() == unitType)
        {
            for (const auto &cell : (*shipIter)->getCells())
            {
                if (cell.at(ROW) == position.at(ROW) && cell.at(COL) == position.at(COL))
                {
                    result = *shipIter;

                    //erases ship and goes to next!
                    shipIter = m_ships.erase(shipIter);

                    break;
                }
            }
        }

        if (result != nullptr)
        {
            break;
        }
        else
        {
            shipIter++;
        }
    }

    if (result != nullptr)
    {
        for (const auto &cell : result->getCells())
        {
            at(cell.at(ROW), cell.at(COL), W);
        }
    }

    return result;
}

Ship *Board::removeUnit(const UnitType unitType, const Coordinate position)
{
    Ship *result = nullptr;

    try
    {
        at(position.at(ROW), position.at(COL));
    }
    catch (std::out_of_range e)
    {
        result = nullptr;
    }

    auto shipIter = m_ships.begin();

    while (shipIter != m_ships.end())
    {
        if ((*shipIter)->getUnitType() == unitType)
        {
            for (auto &cell : (*shipIter)->getCells())
            {
                if (cell.at(ROW) == position.at(ROW) && cell.at(COL) == position.at(COL))
                {
                    result = *shipIter;

                    //erases ship and goes to next!
                    shipIter = m_ships.erase(shipIter);

                    break;
                }
            }
        }
        if (result != nullptr)
        {
            break;
        }
    }

    return result;
}

Coordinate Board::string_to_Coordinate(const std::string sPosition)
{
    Coordinate result;

    char column = toupper(sPosition.at(0));

    if (column >= 'A' && column <= 'N')
    {
        try
        {
            uint8_t row = std::stoi(sPosition.substr(1));

            if (row >= 1)
            {
                result = Coordinate(row - 1, column - 'A');
            }
            else
            {
                throw std::out_of_range("Row must equal or greater than 1!");
            }
        }
        catch (std::invalid_argument &e)
        {
            throw e;
        }
    }
    else
    {
        throw std::out_of_range("Column must be a single letter!");
    }

    return result;
}

std::string Board::testShipPosition(Ship *ship)
{
    std::stringstream result;

    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;
    result << std::setw(3) << ' ' << ".............." << std::endl;

    bool gotShip = false;

    for (int r = 0; r < ROWS; r++)
    {

        result << std::setw(2) << (r + 1) << '|';

        for (int c = 0; c < COLS; c++)
        {
            for (auto cell : ship->getCells())
            {
                if (r == cell.at(ROW) && c == cell.at(COL))
                {
                    result << '+';
                    gotShip = true;
                }
            }

            if (!gotShip)
            {
                result << this->at(r, c);
                gotShip = false;
            }
        }

        result << '|' << std::setw(3) << (r + 1);

        result << std::endl;
    }

    result << std::setw(3) << ' ' << "''''''''''''''" << std::endl;
    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;

    return result.str();
}

Board::Board(const Board &otherBoard)
    : m_grid{{W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W,
              W, W, W, W, W, W, W, W, W, W, W, W, W, W}}
{
    std::copy(otherBoard.m_grid.begin(), otherBoard.m_grid.end(), this->m_grid.begin());

    for (auto s : otherBoard.m_ships)
    {
        *this << s->clone();
    }
}

#undef W

//double size
/*
std::string Board::toString() const
{
    std::stringstream result;

    result << std::setw(3) << ' ' << "A B C D E F G H I J K L M N " << std::endl;
    result << std::setw(3) << ' ' << "............................" << std::endl;

    bool toggle = true;

    for(int r = 0; r < ROWS; r++)
    {
        if(toggle)
        {
            result << std::setw(2) << (r + 1) << '|';
        }
        else
        {
            result << std::setw(3) << '|';
        }

        for(int c = 0; c < COLS; c++)
        {
            result << this->at(r, c) << this->at(r, c);
        }

        if(toggle)
        {
            result << '|' << std::setw(2) << (r + 1);
        }
        else
        {
            result << '|';
        }

        result << std::endl;

        if(toggle)
        {
            r--;
        }
        toggle = !toggle;
    }

    result << std::setw(3) << ' ' << "............................" << std::endl;
    result << std::setw(3) << ' ' << "A B C D E F G H I J K L M N " << std::endl;

    return result.str();
}
*/
