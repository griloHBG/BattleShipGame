//
// Created by Grilo on 6/19/2019.
//

#ifndef BATTLESHIP_LINEARSHIP_H
#define BATTLESHIP_LINEARSHIP_H

#include "Ship.h"

class LinearShip: public Ship
{
public:
    explicit LinearShip(size_t numCells);
    LinearShip(size_t numCells, Coordinate rotationCenter, ShipDirection direction);
    LinearShip(size_t numCells, const std::string& srotationCenter, ShipDirection direction);
    void setupRemainingShip(ShipDirection direction) override;
};


#endif //BATTLESHIP_DESTROYER_H

