/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains MasterBedRoom Class Prototype
*********************************************************************/

#ifndef MASTERBEDROOM_H
#define MASTERBEDROOM_H
#include "Room.h"

class MasterBedRoom : public Room
{
protected:
	Container bed;
	Container dresser;
	Item* dumbwaiterKey;
	Item* shirt;
	Item* fenceKey;
public:
	MasterBedRoom();
	virtual ~MasterBedRoom();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif