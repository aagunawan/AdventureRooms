/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Room Class Prototype
*********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "CommonArea.h"
#include "LivingRoom.h"
#include "Outside.h"
#include "Kitchen.h"
#include "MasterBedRoom.h"
#include "BathRoom.h"
#include "DiningRoom.h"
#include "LaundryRoom.h"
#include <time.h>
#include <cstdlib>

class Game
{
private:
	Room* commonArea;
	Room* livingRoom;	
	Room* outside;
	Room* masterBedRoom;
	Room* kitchen;	
	Room* laundryRoom;
	Room* diningRoom;
	Room* bathRoom;
	bool isvalid;
	time_t start, end;
	int timeRemain;
	bool isTimeUp;
	
	// chef properties
	Room* currentLoc;
	Container* bag;
	Item* item;
	int numItem; // var to hold number of bag items
	
	int choice;

public:
	Game();
	~Game();
	void play();
	};
	
#endif