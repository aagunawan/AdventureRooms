/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Room Class Prototype
*********************************************************************/

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include "Item.h"
#include "Container.h"

class Room
{
protected:
	Room *front;
	Room *back;
	Room *left;
	Room *right;
	bool valid;
	int choice;
	char answer;
	std::string roomName;
	std::string itemName;
	int index;
	static bool isFenceKeyOut;
	static bool isChickenOrdered;
	


	
public:
	Room();
	virtual ~Room();
	int enter();
	virtual Item* explore() = 0;
	virtual void interact(Container*) = 0;
	virtual Room* changeRoom() = 0;
	Room* getFront();
	virtual void setAdjacent(Room*, Room*, Room*, Room*, Room*) = 0;
	std::string getRoomName();	
	bool getFenceKeyStatus();
	void setFenceKeyStatus(bool);
	bool getChickenOrderStatus();
	void setChickenOrderStatus(bool);
	};

#endif