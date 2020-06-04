/*
 * board.h
 *
 *  Created on: Jun 16, 2019
 *      Author: Grilo
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <iomanip>

#include "../ships/ship/Ship.h"

enum ShipAppendResult
{
    APPENDED,
    NOT_APPENDED_TOO_CLOSE,
    NOT_APPENDED_OUT_OF_BOUNDS
};

enum ShipRemoveResult
{
    REMOVED,
    NOT_REMOVED_WRONG_SHIP,
    NOT_REMOVED_OUT_OF_BOUNDS
};

class Board
{

private:
    std::array<char, 14 * 14> m_grid;
    std::vector<Ship *> m_ships;

    std::string toString() const;
    void at(const uint8_t &row, const uint8_t &col, const uint8_t &value);
    char at(const uint8_t &row, const uint8_t &col) const;
    void boundCheck(const uint8_t &row, const uint8_t &col) const;

public:
    Board();
    Board(const Board &otherBoard);

    virtual ~Board();

    static const uint8_t ROWS = 14;
    static const uint8_t COLS = 14;
    friend std::ostream &operator<<(std::ostream &out, const Board &Board);
    std::string testShipPosition(Ship *ship);
    ShipAppendResult operator<<(Ship *ship);

    Ship *removeUnit(const UnitType unitType, const std::string &sPosition);
    Ship *removeUnit(const UnitType unitType, const Coordinate position);

    static Coordinate string_to_Coordinate(const std::string sPosition);
};

#endif

/* BOARD_H_ */