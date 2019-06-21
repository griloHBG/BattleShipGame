//
// Created by Grilo on 6/19/2019.
//

#include "Destroyer.h"

Destroyer::Destroyer(Coordinate rotationCenter, ShipDirection direction)
: LinearShip(2, rotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

Destroyer::Destroyer(const char *sRotationCenter, ShipDirection direction)
: LinearShip(2, sRotationCenter, direction)
{
    placeShip(m_rotationCenter, direction);
}

Destroyer::Destroyer()
:LinearShip(2)
{

}

char Destroyer::getSymbol() const
{
    return 'd';
}

std::string Destroyer::getShipName() const
{
    return "Destroyer";
}
