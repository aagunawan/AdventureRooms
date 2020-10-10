/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Outside Class Prototype
*********************************************************************/

#ifndef OUTSIDE_H
#define OUTSIDE_H
#include "Room.h"

class Outside : public Room
{
public:
	Outside();
	virtual ~Outside();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	void interact(Container*);
	Item* explore();
	Room* changeRoom();
	};

#endif