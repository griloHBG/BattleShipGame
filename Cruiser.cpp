//
// Created by Grilo on 6/20/2019.
//

#include "Cruiser.h"

Cruiser::Cruiser()
:LinearShip(4)
{

}

Cruiser::Cruiser(Coordinate rotationCenter, ShipDirection direction)
:LinearShip(4, rotationCenter, direction)
{

}

Cruiser::Cruiser(const char *sRotationCenter, ShipDirection direction)
:LinearShip(4, sRotationCenter, direction)
{

}

char Cruiser::getSymbol() const
{
    return 'c';
}

std::string Cruiser::getShipName() const
{
    return "Cruiser";
}

Cruiser *Cruiser::clone() const
{
    return( new Cruiser( *this ) );
}
