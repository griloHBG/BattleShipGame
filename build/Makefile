FLAGS=-Wall \
			-Wextra \
			-g

VALGRIND_FLAGS=--tool=memcheck \
							 --leak-check=yes \
							 --show-reachable=yes \
							 --num-callers=20 \
							 --track-fds=yes

NCURSES_FLAG=-lncurses

CC=g++

MAIN_PATH=../main.cpp

AUX_FILE=../aux/Aux.cpp
AUX_LIBRARY=../aux/Aux.h

BOARD_FILE=../board/Board.cpp
BOARD_LIBRARY=../board/Board.h

COORDINATE_FILE=../coordinate/Coordinate.cpp
COORDINATE_LIBRARY=../coordinate/Coordinate.h

GENERAL_FILE=../general/General.cpp
GENERAL_LIBRARY=../general/General.h

SHIP_FILE=../ships/ship/Ship.cpp
SHIP_LIBRARY=../ships/ship/Ship.h

CARRIER_FILE=../ships/carrier/Carrier.cpp
CARRIER_LIBRARY=../ships/carrier/Carrier.h

CRUISER_FILE=../ships/cruiser/Cruiser.cpp
CRUISER_LIBRARY=../ships/cruiser/Cruiser.h

DESTROYER_FILE=../ships/destroyer/Destroyer.cpp
DESTROYER_LIBRARY=../ships/destroyer/Destroyer.h

HYDROPLANE_FILE=../ships/hydroPlane/HydroPlane.cpp
HYDROPLANE_LIBRARY=../ships/hydroPlane/HydroPlane.h

LINEARSHIP_FILE=../ships/linearShip/LinearShip.cpp
LINEARSHIP_LIBRARY=../ships/linearShip/LinearShip.h

SUBMARINE_FILE=../ships/submarine/Submarine.cpp
SUBMARINE_LIBRARY=../ships/submarine/Submarine.h

DESTINATION_PATH=battleship

OBJECT_FILES=Aux.o \
							Board.o \
							Coordinate.o \
							General.o \
							Ship.o \
							Carrier.o \
							Cruiser.o \
							Destroyer.o \
							HydroPlane.o \
							LinearShip.o \
							Submarine.o \
							main.o

aux: $(AUX_FILE) $(AUX_LIBRARY) 
	$(CC) $(FLAGS) -c $(AUX_FILE) 

board: $(BOARD_FILE) $(BOARD_LIBRARY) 
	$(CC) $(FLAGS) -c $(BOARD_FILE) 

coordinate: $(COORDINATE_FILE) $(COORDINATE_LIBRARY)
	$(CC) $(FLAGS) -c $(COORDINATE_FILE)

general: $(GENERAL_FILE) $(GENERAL_LIBRARY)
	$(CC) $(FLAGS) -c $(GENERAL_FILE)

ship: $(SHIP_FILE) $(SHIP_LIBRARY)
	$(CC) $(FLAGS) -c $(SHIP_FILE)

carrier: $(CARRIER_FILE) $(CARRIER_LIBRARY)
	$(CC) $(FLAGS) -c $(CARRIER_FILE)

cruiser: $(CRUISER_FILE) $(CRUISER_LIBRARY)
	$(CC) $(FLAGS) -c $(CRUISER_FILE)

destroyer: $(DESTROYER_FILE) $(DESTROYER_LIBRARY)
	$(CC) $(FLAGS) -c $(DESTROYER_FILE)

hydroplane: $(HYDROPLANE_FILE) $(HYDROPLANE_LIBRARY)
	$(CC) $(FLAGS) -c $(HYDROPLANE_FILE)

linearship: $(LINEARSHIP_FILE) $(LINEARSHIP_LIBRARY)
	$(CC) $(FLAGS) -c $(LINEARSHIP_FILE)

submarine: $(SUBMARINE_FILE) $(SUBMARINE_LIBRARY)
	$(CC) $(FLAGS) -c $(SUBMARINE_FILE)

main: $(MAIN_PATH)
	$(CC) $(FLAGS) -c $(MAIN_PATH)

objects: aux board coordinate general ship carrier cruiser destroyer hydroplane linearship submarine main
	echo 'Arquivos .o foram criados com sucesso'

game: $(OBJECT_FILES)
	$(CC) -o $(DESTINATION_PATH) $(OBJECT_FILES) $(NCURSES_FLAG)

run: $(DESTINATION_PATH)
	valgrind $(VALGRIND_FLAGS) ./$(DESTINATION_PATH)

play: $(DESTINATION_PATH)
	./$(DESTINATION_PATH)
