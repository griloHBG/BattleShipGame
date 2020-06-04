/*
 * Coordinates.h
 *
 *  Created on: Jun 17, 2019
 *      Author: Grilo
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <array>
#include <ostream>
#include <sstream>

const uint8_t ROW = 0;
const uint8_t COL = 1;

class Coordinate : public std::array<uint8_t, 2>
{
public:
    Coordinate();
	Coordinate(const uint8_t& row, const uint8_t& col);
	Coordinate& operator+=(const Coordinate& rhs);
	friend Coordinate operator+(Coordinate lhs, const Coordinate& rhs);
	Coordinate& operator+=(const std::array<uint8_t, 2>& rhs);
	friend Coordinate operator+(Coordinate lhs, const std::array<uint8_t, 2>& rhs);

	friend uint8_t operator-(Coordinate lhs, const Coordinate& rhs);;
	friend uint8_t operator-(Coordinate lhs, const std::array<uint8_t, 2>& rhs);

	friend std::ostream& operator<<(std::ostream& out, const Coordinate& coordinate);
    std::string toString() const;


};
#endif /* COORDINATES_H_ */
