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
    HydroPlane(const char sRotationCenter[], ShipDirection direction);

    char getSymbol() const override;

    std::string getShipName() const override;
};


#endif //BATTLESHIP_HYDROPLANE_H
