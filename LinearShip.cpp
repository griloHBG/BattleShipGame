//
// Created by Grilo on 6/19/2019.
//

#include "LinearShip.h"

void LinearShip::setupRemainingShip(ShipDirection direction)
{
    for(int c = 1; c < getSize(); c++)
    {
        switch (direction)
        {
            case ShipDirection::NORTH:
                m_cells.at(c).at(ROW) = m_rotationCenter.at(ROW) - c;
                m_cells.at(c).at(COL) = m_rotationCenter.at(COL);
                break;
            case ShipDirection::EAST:
                m_cells.at(c).at(ROW) = m_rotationCenter.at(ROW);
                m_cells.at(c).at(COL) = m_rotationCenter.at(COL) + c;
                break;
            case ShipDirection::SOUTH:
                m_cells.at(c).at(ROW) = m_rotationCenter.at(ROW) + c;
                m_cells.at(c).at(COL) = m_rotationCenter.at(COL);
                break;
            case ShipDirection::WEST:
                m_cells.at(c).at(ROW) = m_rotationCenter.at(ROW);
                m_cells.at(c).at(COL) = m_rotationCenter.at(COL) - c;
                break;
            case ShipDirection::UNDEFINED:
                //nao deveria acontecer!
                break;
        }
    }
}

LinearShip::LinearShip(size_t numCells, Coordinate rotationCenter, ShipDirection direction)
        : Ship(numCells, rotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

LinearShip::LinearShip(size_t numCells, const char *srotationCenter, ShipDirection direction)
: Ship(numCells, srotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

LinearShip::LinearShip(size_t numCells)
: Ship(numCells)
{

}