/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Living Room Class Prototype
*********************************************************************/

#ifndef LIVINGROOM_H
#define LIVINGROOM_H
#include "Room.h"

class LivingRoom : public Room
{
protected:
	Container TV;
	Container couch;
	Container cabinet;
	Container table;
	Item *remoteControl;
	Item *wirelessPhone;
	Item *charger;
	
public:
	LivingRoom();
	virtual ~LivingRoom();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	Item* explore();
	Room* changeRoom();
	void interact(Container*);
	};

#endif