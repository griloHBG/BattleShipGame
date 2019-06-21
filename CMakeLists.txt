cmake_minimum_required(VERSION 3.13)
project(battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable( battleship main.cpp
                Coordinate.cpp
                Field.cpp
                Ship.cpp
                LinearShip.cpp
                Submarine.cpp
                Destroyer.cpp
                Carrier.cpp
                HydroPlane.cpp
        Cruiser.cpp Cruiser.h ShipStuff.h)