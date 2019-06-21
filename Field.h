/*
 * Field.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <iomanip>

#include "Ship.h"

enum ShipAppendResult
{
    APPENDED,
    NOT_APPENDED_TOO_CLOSE,
    NOT_APPENDED_OUT_OF_BOUNDS
};

class Field
{

private:
    std::array<char, 14*14> m_grid;
    std::vector<Ship*> m_ships;

    std::string toString() const;
    void at(const uint8_t& row, const uint8_t& col, const uint8_t& value);
    char at(const uint8_t& row, const uint8_t& col) const;
    void boundCheck(const uint8_t& row, const uint8_t& col) const;

public:
    Field();
    Field(const Field& otherField);

    virtual ~Field();

    static const uint8_t ROWS = 14;
    static const uint8_t COLS = 14;
    friend std::ostream& operator<<(std::ostream& out, const Field& field);
    std::string testShipPosition(Ship* ship);
    ShipAppendResult operator<<(Ship* ship);
};

#endif /* FIELD_H_ */
