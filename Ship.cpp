/*
 * Ship.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#include "Ship.h"

/*Ship::Ship(size_t numCells, Coordinate rotationCenter)
: m_goodParts( numCells ), m_destroyedParts( 0 ), m_rotationCenter(rotationCenter), m_direction( ShipDirection::UNDEFINED )
{
    placeShip(rotationCenter, ShipDirection::UNDEFINED);
}*/

Ship::Ship(size_t numCells, Coordinate rotationCenter, ShipDirection direction )
: m_goodParts( numCells )
    , m_destroyedParts( 0 )
    , m_rotationCenter(rotationCenter)
    , m_direction( direction )
    , m_size(numCells)
    , m_isInitialized(false)
{
}

Ship::Ship(size_t numCells)
: m_goodParts( numCells )
  , m_destroyedParts( 0 )
  , m_rotationCenter(Coordinate(0,0))
  , m_direction( ShipDirection::UNDEFINED )
  , m_size(numCells)
  , m_isInitialized(false)
{

}


Ship::~Ship() = default;

bool Ship::verifyNumCells() const
{
    return (m_cells.size() == getSize());
}

uint8_t Ship::operator-(const Ship& otherShip)
{
	uint8_t minDistance = 0xFF; //255
	uint8_t currentDistance;

	for(auto& thisCell: m_cells)
	{
		for(auto& otherCell: otherShip.m_cells)
		{
			currentDistance = thisCell - otherCell;

			if(currentDistance < minDistance)
			{
				minDistance = currentDistance;
			}
		}
	}

	return minDistance;
}

const std::vector<Coordinate> Ship::getCells() const
{
    return m_cells;
}

char Ship::getSymbol() const
{
    return '_';
}

const Coordinate Ship::getRotationCenter() const
{
    return m_rotationCenter;
}

const ShipCells Ship::placeShip(Coordinate rotationCenter, ShipDirection direction)
{
    if(!m_isInitialized)
    {
        m_cells.clear();
        m_cells.push_back(rotationCenter);

        for(int c = 1; c < getSize(); c++)
        {
            m_cells.emplace_back(Coordinate(0,0));
        }
    }
    else
    {
        m_cells.at(0).at(ROW) = rotationCenter.at(ROW);
        m_cells.at(0).at(COL) = rotationCenter.at(COL);
    }

    m_rotationCenter.at(ROW) = rotationCenter.at(ROW);
    m_rotationCenter.at(COL) = rotationCenter.at(COL);

    setupRemainingShip(direction);

    m_isInitialized = true;

    return m_cells;
}

const uint8_t Ship::getSize() const
{
    return m_size;
}

Ship::Ship(size_t numCells, const std::string& sRotationCenter, ShipDirection direction)
        : m_goodParts( numCells )
          , m_destroyedParts( 0 )
          , m_direction( direction )
          , m_size(numCells)
          , m_isInitialized(false)
{

    char column = toupper(sRotationCenter.at(0));

    if(column >= 'A' && column <= 'N')
    {
        try
        {
            uint8_t row = std::stoi(sRotationCenter.substr(1));

            if(row >= 1)
            {
                m_rotationCenter = Coordinate(row - 1, column - 'A');
            }
            else
            {
                throw std::out_of_range("Row must equal or greater than 1!");
            }
        }
        catch(std::invalid_argument& e)
        {
            throw e;
        }
    }
    else
    {
        throw std::out_of_range("Column must be a single letter!");
    }
}
