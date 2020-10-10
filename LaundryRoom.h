/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains laundryRoom Class Prototype
*********************************************************************/

#ifndef LAUNDRYROOM_H
#define LAUNDRYROOM_H
#include "Room.h"

class LaundryRoom : public Room
{
protected:
	Container dumbwaiter;
	Container door;
	Container laundryMachine;
	Item *stickyNote;
	Item *towel;
	Item *chickenWings;
	Item *pepper;
	Item *salt;
	Item *oil;
	Item *ginger;
	Item *soySauce;
	
public:
	LaundryRoom();
	virtual ~LaundryRoom();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif