/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Common Area Class Prototype
*********************************************************************/

#ifndef COMMONAREA_H
#define COMMONAREA_H
#include "Room.h"

class CommonArea : public Room
{
protected:
	Room *up;
	Container rug;
	Container pictures;
	Item *letter;
	Item *pin;
	std::string itemToAdd;
	
public:
	CommonArea();
	virtual ~CommonArea();
	void setAdjacent(Room*, Room*, Room*, Room*, Room*);
	//virtual void setUpRoom(Room*);
	void interact(Container*);
	Item* explore();
	Room* changeRoom();
	void flipRug();
	void lookBehindPictures();
	};

#endif