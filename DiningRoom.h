/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains DiningRoom Class Prototype
*********************************************************************/

#ifndef DININGROOM_H
#define DININGROOM_H
#include "Room.h"

class DiningRoom : public Room
{
protected:
	Container plate;
	Container chair;
	Container tableRunner;
	Item* mainGateKey;
public:
	DiningRoom();
	virtual ~DiningRoom();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif