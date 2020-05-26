//
// Created by Grilo on 6/20/2019.
//

#ifndef BATTLESHIP_HYDROPLANE_H
#define BATTLESHIP_HYDROPLANE_H

#include "Ship.h"

class HydroPlane: public Ship
{
private:
    void setupRemainingShip(ShipDirection direction) override;

public:
    HydroPlane();
    HydroPlane(Coordinate rotationCenter, ShipDirection direction);
    HydroPlane(const std::string& sRotationCenter, ShipDirection direction);

    char getSymbol() const override;

    std::string getShipName() const override;
    HydroPlane* clone() const override;
    UnitType getUnitType() const override;
};


#endif //BATTLESHIP_HYDROPLANE_H
