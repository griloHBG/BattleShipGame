/*
 * Submarine.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: Grilo
 */

#include "Submarine.h"

Submarine::Submarine(Coordinate rotationCenter)
: LinearShip(1, rotationCenter, ShipDirection::NORTH)
{
	placeShip(rotationCenter, m_direction);
}

std::string Submarine::getShipName() const
{
    return "Submarine";
}

char Submarine::getSymbol() const
{
    return 's';
}

Submarine::Submarine(const char *sRotationCenter)
: LinearShip(1, sRotationCenter, ShipDirection::NORTH)
{

}

Submarine::Submarine()
:LinearShip(1)
{

}

Submarine* Submarine::clone() const
{
    return( new Submarine( *this ) );
}
