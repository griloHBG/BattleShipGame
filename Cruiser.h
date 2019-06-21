//
// Created by Grilo on 6/20/2019.
//

#ifndef BATTLESHIP_CRUISER_H
#define BATTLESHIP_CRUISER_H

#include "LinearShip.h"

class Cruiser: public LinearShip
{
public:
    Cruiser();
    Cruiser(Coordinate rotationCenter, ShipDirection direction);
    Cruiser(const char sRotationCenter[], ShipDirection direction);
    char getSymbol() const override;
    std::string getShipName() const override;
    Cruiser* clone() const override;
};


#endif //BATTLESHIP_CRUISER_H
