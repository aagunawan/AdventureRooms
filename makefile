
all: Final clean

Final: Main.o Room.cpp CommonArea.cpp LivingRoom.cpp Game.cpp Item.cpp Container.cpp Outside.cpp Kitchen.cpp DiningRoom.cpp LaundryRoom.cpp MasterBedRoom.cpp BathRoom.cpp 
	g++ Main.o Room.cpp CommonArea.cpp LivingRoom.cpp Game.cpp Item.cpp Container.cpp Outside.cpp Kitchen.cpp DiningRoom.cpp LaundryRoom.cpp MasterBedRoom.cpp BathRoom.cpp -o Final

Main.o: Main.cpp
	g++ -c Main.cpp
	
Room.o: Room.cpp
	g++ -c Room.cpp

CommonArea.o: CommonArea.cpp 
	g++ -c CommonArea.cpp

Game.o: Game.cpp
	g++ -c Game.cpp
	
Item.o: Item.cpp
	g++ -c Item.cpp

Container.o: Container.cpp
	g++ -c Container.cpp

Outside.o: Outside.cpp
	g++ -c Outside.cpp

Kitchen.o: Kitchen.cpp
	g++ -c Kitchen.cpp

DiningRoom.o: DiningRoom.cpp
	g++ -c DiningRoom.cpp

LaundryRoom.o: LaundryRoom.cpp
	g++ -c LaundryRoom.cpp

MasterBedRoom.o: MasterBedRoom.cpp
	g++ -c MasterBedRoom.cpp

BathRoom.o: BathRoom.cpp
	g++ -c BathRoom.cpp

clean:
	-rm *.o