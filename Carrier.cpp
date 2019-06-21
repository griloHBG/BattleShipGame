//
// Created by Grilo on 6/19/2019.
//

#include "Carrier.h"

Carrier::Carrier(Coordinate rotationCenter, ShipDirection direction)
        : LinearShip(5, rotationCenter, direction)
{
    placeShip(rotationCenter, direction);
}

char Carrier::getSymbol() const
{
    return 'C';
}

std::string Carrier::getShipName() const
{
    return "Carrier";
}

Carrier::Carrier()
:LinearShip(5)
{

}
