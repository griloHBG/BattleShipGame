//
// Created by Grilo on 6/19/2019.
//

#ifndef BATTLESHIP_CARRIER_H
#define BATTLESHIP_CARRIER_H

#include "../linearShip/LinearShip.h"

class Carrier : public LinearShip
{
public:
    Carrier();
    Carrier(Coordinate rotationCenter, ShipDirection direction);
    Carrier(const std::string &sRotationCenter, ShipDirection direction);
    char getSymbol() const override;
    std::string getShipName() const override;
    Carrier *clone() const override;
    UnitType getUnitType() const override;
};

#endif //BATTLESHIP_CARRIER_H
