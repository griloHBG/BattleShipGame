/*
 * Coordinates.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: Grilo
 */

#include "Coordinate.h"

Coordinate::Coordinate(const uint8_t& row, const uint8_t& col)
:std::array<uint8_t, 2>()
{
	this->at(ROW) = row;
	this->at(COL) = col;
}
Coordinate& Coordinate::operator+=(const Coordinate& rhs) // compound assignment (does not need to be a member,
{                           // but often is, to modify the private members)
	this->at(ROW) += rhs.at(ROW);
	this->at(COL) += rhs.at(COL);
	return *this; // return the result by reference
}

// friends defined inside class body are inline and are hidden from non-ADL lookup
// passing lhs by value helps optimize chained a+b+c
// otherwise, both parameters may be const references
Coordinate operator+(Coordinate lhs, const Coordinate& rhs)
{
	lhs += rhs; // reuse compound assignment
	return lhs; // return the result by value (uses move constructor)
}

Coordinate& Coordinate::operator+=(const std::array<uint8_t, 2>& rhs)
{
	this->at(ROW) += rhs.at(ROW);
	this->at(COL) += rhs.at(COL);
	return *this;
}

Coordinate operator+(Coordinate lhs, const std::array<uint8_t, 2>& rhs)
{
	lhs += rhs;
	return lhs;
}

uint8_t operator-(Coordinate lhs, const Coordinate& rhs)
{
	return std::max(std::abs(lhs.at(ROW)-rhs.at(ROW)),
					std::abs(lhs.at(COL)-rhs.at(COL)));
}

uint8_t operator-(Coordinate lhs, const std::array<uint8_t, 2>& rhs)
{
	return std::max(std::abs(lhs.at(ROW)-rhs.at(ROW)),
					std::abs(lhs.at(COL)-rhs.at(COL)));
}

std::ostream& operator<<(std::ostream& out, const Coordinate& coordinate)
{
    out << coordinate.toString();

    return out;
}

std::string Coordinate::toString() const
{
    std::stringstream ss;

    ss << static_cast<char>(at(COL) + 'A') << static_cast<int>(at(ROW) + 1);

    return ss.str();
}

Coordinate::Coordinate()
:std::array<uint8_t, 2>()
{
    this->at(ROW) = 0;
    this->at(COL) = 0;
}
