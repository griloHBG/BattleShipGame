//
// Created by Grilo on 6/22/2019.
//

#include "General.h"

General::General(const std::string& name, const std::string& country)
: m_name(name), m_country(country), m_remainingCarrier(1), m_remainingCruiser(2), m_remainingHydroPlane(3), m_remainingDestroyer(4), m_remainingSubmarine(5)
{

}

std::string General::getCountry() const
{
    return m_country;
}

int General::getRemaining(UnitType unitType) const
{
    int result;

    switch(unitType)
    {
        case UnitType::CARRIER:
            result = m_remainingCarrier;
            break;
        case UnitType::CRUISER:
            result = m_remainingCruiser;
            break;
        case UnitType::HYDROPLANE:
            result = m_remainingHydroPlane;
            break;
        case UnitType::DESTROYER:
            result = m_remainingDestroyer;
            break;
        case UnitType::SUBMARINE:
            result = m_remainingSubmarine;
            break;
        default:
            //should not happen
            result = -1;
    }

    return result;
}

std::string General::getName() const
{
    return m_name;
}

int General::operator-(const UnitType& unitType)
{
    int result = -1;

    switch(unitType)
    {
        case UnitType::CARRIER:
            result = (--m_remainingCarrier);
            break;
        case UnitType::CRUISER:
            result = (--m_remainingCruiser);
            break;
        case UnitType::HYDROPLANE:
            result = (--m_remainingHydroPlane);
            break;
        case UnitType::DESTROYER:
            result = (--m_remainingDestroyer);
            break;
        case UnitType::SUBMARINE:
            result = (--m_remainingSubmarine);
            break;
        default:
            //should not happen
            result = -1;
    }

    if(result < 0)
    {
        throw std::out_of_range("This UNIT (" + std::to_string(unitType) + ")couldn't be used!");
    }

    return result;
}

int General::getSumRemaining() const
{
    return  m_remainingCarrier +
            m_remainingCruiser +
            m_remainingHydroPlane +
            m_remainingDestroyer +
            m_remainingSubmarine;
}

int General::tryUseUnit(uint8_t remainingUnit)
{
    return remainingUnit - 1;
}

std::ostream& operator<<(std::ostream& out, const General& general)
{
    return out << general.getName();
}


Ship* General::makeShip(const UnitType &unitType, const Coordinate& position, const ShipDirection &direction)
{
    Ship* resultShip = nullptr;

    if(*this - unitType >= 0)
    {
        switch (unitType)
        {
            case CARRIER:
                resultShip = new Carrier(position, direction);
                break;
            case CRUISER:
                resultShip = new Cruiser(position, direction);
                break;
            case HYDROPLANE:
                resultShip = new HydroPlane(position, direction);
                break;
            case DESTROYER:
                resultShip = new Destroyer(position, direction);
                break;
            case SUBMARINE:
                resultShip = new Submarine(position);
                break;
        }
    }

    return resultShip;
}

Ship* General::makeShip(const UnitType &unitType, const std::string &sPosition, const ShipDirection &direction)
{
    Ship* resultShip = nullptr;

    if(getRemaining(unitType) >= 1)
    {
        switch (unitType)
        {
            case CARRIER:
                resultShip = new Carrier(sPosition, direction);
                break;
            case CRUISER:
                resultShip = new Cruiser(sPosition, direction);
                break;
            case HYDROPLANE:
                resultShip = new HydroPlane(sPosition, direction);
                break;
            case DESTROYER:
                resultShip = new Destroyer(sPosition, direction);
                break;
            case SUBMARINE:
                resultShip = new Submarine(sPosition);
                break;
        }
    }

    return resultShip;
}
