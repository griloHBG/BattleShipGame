//
// Created by Grilo on 6/20/2019.
//

#ifndef BATTLESHIP_CRUISER_H
#define BATTLESHIP_CRUISER_H

#include "../linearShip/LinearShip.h"

class Cruiser : public LinearShip
{
public:
    Cruiser();
    Cruiser(Coordinate rotationCenter, ShipDirection direction);
    Cruiser(const std::string &sRotationCenter, ShipDirection direction);
    char getSymbol() const override;
    std::string getShipName() const override;
    Cruiser *clone() const override;
    UnitType getUnitType() const override;
};

#endif //BATTLESHIP_CRUISER_H
