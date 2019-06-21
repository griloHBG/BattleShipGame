/*
 * Ship.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Coordinate.h"

using ShipCells = std::vector<Coordinate>;

enum ShipDirection
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	UNDEFINED
};

class Ship
{
public:
	//Ship(size_t numCells, Coordinate rotationCenter);
    explicit Ship(size_t numCells);
	Ship(size_t numCells, Coordinate rotationCenter, ShipDirection direction);
    Ship(size_t numCells, const char sRotationCenter[], ShipDirection direction);
    virtual ~Ship();

    virtual char getSymbol() const;
    virtual std::string getShipName() const = 0;

    const ShipCells placeShip(Coordinate rotationCenter, ShipDirection direction = ShipDirection::NORTH);
    const std::vector<Coordinate> getCells() const;
    const Coordinate getRotationCenter() const;

    uint8_t operator-(const Ship& otherShip);

protected:
    size_t m_size;
	uint8_t m_goodParts;
	uint8_t m_destroyedParts;
    ShipCells m_cells;
    Coordinate m_rotationCenter;
    ShipDirection m_direction;

    virtual void setupRemainingShip(ShipDirection direction) = 0;

	bool verifyNumCells() const;
    const uint8_t getSize() const;

private:
    bool m_isInitialized = false;
};

#endif /* SHIP_H_ */
