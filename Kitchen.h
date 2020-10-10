/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Kitchen Class Prototype
*********************************************************************/

#ifndef KITCHEN_H
#define KITCHEN_H
#include "Room.h"

class Kitchen : public Room
{
protected:
	Container cabinet1;
	Container cabinet2;
	Container drawer;
	Container countertop;
	Item *knife;
	Item *cuttingBoard;
	Item *deepFryer;
	Item *bowl;
	Item *cookedChicken;
	int mixerCounter; // indicates how many items have been mixed
public:
	Kitchen();
	virtual ~Kitchen();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif