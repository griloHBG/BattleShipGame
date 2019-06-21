//
// Created by Grilo on 6/19/2019.
//

#ifndef BATTLESHIP_DESTROYER_H
#define BATTLESHIP_DESTROYER_H

#include "LinearShip.h"

class Destroyer: public LinearShip
{
public:
    Destroyer();
    Destroyer(Coordinate rotationCenter, ShipDirection direction);
    Destroyer(const char sRotationCenter[], ShipDirection direction);
    char getSymbol() const override;
    std::string getShipName() const override;
    Destroyer* clone() const override;
};


#endif //BATTLESHIP_DESTROYER_H
