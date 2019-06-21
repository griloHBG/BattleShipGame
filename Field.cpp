/*
 * Field.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#include "Field.h"

#define W ' '

Field::Field()
:m_grid{{	W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W  }}
{
}

#undef W

Field::~Field()  = default;

std::ostream& operator<<(std::ostream& out, const Field& field)
{
    return out << field.toString();
}

ShipAppendResult Field::operator<<(Ship* ship)
{
    ShipAppendResult result = ShipAppendResult::APPENDED;

    for(auto fieldShip : this->m_ships)
    {
        int a = *fieldShip - *ship;
        if(a < 2)
        {
            result = ShipAppendResult::NOT_APPENDED_TOO_CLOSE;
            //std::cout << "Cada embarcação precisa ficar a, pelo menos, uma fila de célula de distância de outra embarcação\n";
        }
    }

    if(result == ShipAppendResult::APPENDED)
    {
        for(auto cell : ship->getCells())
        {
            try
            {
                this->at(cell.at(ROW), cell.at(COL));
            }
            catch(std::out_of_range& e)
            {
                result = ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS;
                break;
            }
        }

        if(result != ShipAppendResult::NOT_APPENDED_OUT_OF_BOUNDS)
        {
            this->m_ships.push_back(ship);

            for(auto cell : ship->getCells())
            {
                this->at(cell.at(ROW), cell.at(COL), ship->getSymbol());
            }
        }
    }

    return result;
}

char Field::at(const uint8_t& row, const uint8_t& col) const
{
    try
    {
        boundCheck(row, col);
    }
    catch (std::out_of_range& e)
    {
        throw e;
    }

    return m_grid.at( row*ROWS + col );
}

std::string Field::toString() const
{
    std::stringstream result;

    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;
    result << std::setw(3) << ' ' << ".............." << std::endl;

    for(int r = 0; r < ROWS; r++)
    {

        result << std::setw(2) << (r+1) << '|';

        for(int c = 0; c < COLS; c++)
        {
            result << this->at(r, c);
        }

        result << '|' << std::setw(3) << (r+1);

        result << std::endl;
    }

    result << std::setw(3) << ' ' << "''''''''''''''" << std::endl;
    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;

    return result.str();
}

void Field::at(const uint8_t& row, const uint8_t& col, const uint8_t& value)
{

    try
    {
        boundCheck(row, col);
    }
    catch (std::out_of_range& e)
    {
        throw e;
    }

    m_grid.at( row*ROWS + col ) = value;
}

void Field::boundCheck(const uint8_t& row, const uint8_t& col) const
{
    try
    {
        if(row < 0)
        {
            throw std::out_of_range("Row cant be negative");
        }

        if(col < 0)
        {
            throw std::out_of_range("Col cant be negative");
        }

        if(row >= ROWS)
        {
            throw std::out_of_range("Row cant be greater than " + std::to_string(ROWS));
        }

        if(col >= COLS)
        {
            throw std::out_of_range("Col cant be greater than " + std::to_string(COLS));
        }
    }
    catch(std::out_of_range& e)
    {
        throw e;
    }
}

std::string Field::testShipPosition(Ship* ship)
{
    std::stringstream result;

    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;
    result << std::setw(3) << ' ' << ".............." << std::endl;

    bool gotShip = false;

    for(int r = 0; r < ROWS; r++)
    {

        result << std::setw(2) << (r+1) << '|';

        for(int c = 0; c < COLS; c++)
        {
            for(auto cell : ship->getCells())
            {
                if(r == cell.at(ROW) && c == cell.at(COL))
                {
                    result << '+';
                    gotShip = true;
                }
            }

            if(!gotShip)
            {
                result << this->at(r, c);
                gotShip = false;
            }
        }

        result << '|' << std::setw(3) << (r+1);

        result << std::endl;
    }

    result << std::setw(3) << ' ' << "''''''''''''''" << std::endl;
    result << std::setw(3) << ' ' << "ABCDEFGHIJKLMN" << std::endl;

    return result.str();
}

#define W ' '
Field::Field(const Field& otherField)
:m_grid{{	W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W ,
            W , W , W , W , W , W , W , W , W , W , W , W , W , W  }}
{
    std::copy(otherField.m_grid.begin(), otherField.m_grid.end(), this->m_grid.begin());

    for(auto s: otherField.m_ships)
    {
        // TODO (*this) << s
    }
}
