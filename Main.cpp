/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
Main Class
*********************************************************************/

#include <iostream>
#include "CommonArea.h"
#include "Game.h"
#include "Room.h"

bool Room::isFenceKeyOut = false;
bool Room::isChickenOrdered = false;

int main()
{
	Game PittockMansion;
	PittockMansion.play();
	}