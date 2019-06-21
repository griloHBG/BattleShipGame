/*
 * Submarine.h
 *
 *  Created on: Jun 17, 2019
 *      Author: Grilo
 */

#ifndef SUBMARINE_H_
#define SUBMARINE_H_

#include "LinearShip.h"

/* Shape: '_' is water and 'o' is part of ship
 * ___
 * _o_
 * ___
 */

class Submarine: public LinearShip
{
public:
    explicit Submarine();
	explicit Submarine(Coordinate rotationCenter);
    explicit Submarine(const char sRotationCenter[]);
	char getSymbol() const override;
	std::string getShipName() const override;
};

#endif /* SUBMARINE_H_ */
