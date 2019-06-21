//
// Created by Grilo on 6/20/2019.
//

#include "HydroPlane.h"

HydroPlane::HydroPlane(Coordinate rotationCenter, ShipDirection direction)
: Ship(3, rotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

HydroPlane::HydroPlane(const char *sRotationCenter, ShipDirection direction)
: Ship(3, sRotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

HydroPlane::HydroPlane()
        :Ship(3)
{
}

void HydroPlane::setupRemainingShip(ShipDirection direction)
{
    switch (direction)
    {
        case ShipDirection::NORTH:
            m_cells.at(0).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(0).at(COL) = m_rotationCenter.at(COL) - 1;

            m_cells.at(1).at(ROW) = m_rotationCenter.at(ROW) - 1;
            m_cells.at(1).at(COL) = m_rotationCenter.at(COL);

            m_cells.at(2).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(2).at(COL) = m_rotationCenter.at(COL) + 1;
            break;

        case ShipDirection::EAST:
            m_cells.at(0).at(ROW) = m_rotationCenter.at(ROW) - 1;
            m_cells.at(0).at(COL) = m_rotationCenter.at(COL);

            m_cells.at(1).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(1).at(COL) = m_rotationCenter.at(COL) + 1;

            m_cells.at(2).at(ROW) = m_rotationCenter.at(ROW) + 1;
            m_cells.at(2).at(COL) = m_rotationCenter.at(COL);
            break;

        case ShipDirection::SOUTH:
            m_cells.at(0).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(0).at(COL) = m_rotationCenter.at(COL) + 1;

            m_cells.at(1).at(ROW) = m_rotationCenter.at(ROW) + 1;
            m_cells.at(1).at(COL) = m_rotationCenter.at(COL);

            m_cells.at(2).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(2).at(COL) = m_rotationCenter.at(COL) - 1;
            break;

        case ShipDirection::WEST:
            m_cells.at(0).at(ROW) = m_rotationCenter.at(ROW) + 1;
            m_cells.at(0).at(COL) = m_rotationCenter.at(COL);

            m_cells.at(1).at(ROW) = m_rotationCenter.at(ROW);
            m_cells.at(1).at(COL) = m_rotationCenter.at(COL) - 1;

            m_cells.at(2).at(ROW) = m_rotationCenter.at(ROW) - 1;
            m_cells.at(2).at(COL) = m_rotationCenter.at(COL);
            break;

        case ShipDirection::UNDEFINED:
            //nao deveria acontecer!
            break;
    }
}

std::string HydroPlane::getShipName() const
{
    return "Hydro Plane";
}

char HydroPlane::getSymbol() const
{
    return 'H';
}