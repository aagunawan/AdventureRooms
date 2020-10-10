/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains BathRoom Class Prototype
*********************************************************************/

#ifndef BATHROOM_H
#define BATHROOM_H
#include "Room.h"

class BathRoom : public Room
{
protected:
	Container window;
public:
	BathRoom();
	virtual ~BathRoom();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif