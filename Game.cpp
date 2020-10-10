/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Game Class Implementation
*********************************************************************/

#include "Game.h"

/*********************************************************************
Game::Game
a default constructor for Game 
*********************************************************************/
Game::Game()
{
	timeRemain = 240; // in minutes
	isTimeUp = false;
	commonArea = new CommonArea;
	livingRoom = new LivingRoom;
	outside = new Outside;
	masterBedRoom = new MasterBedRoom;
	diningRoom = new DiningRoom;
	kitchen = new Kitchen;
	bathRoom = new BathRoom;
	laundryRoom = new LaundryRoom;
	
	commonArea->setAdjacent(livingRoom, masterBedRoom, diningRoom, outside, laundryRoom);
	livingRoom->setAdjacent(NULL, commonArea, NULL, NULL, NULL);
	outside->setAdjacent(NULL, NULL, commonArea, NULL, NULL);
	masterBedRoom->setAdjacent(commonArea, bathRoom, NULL, NULL, NULL);
	diningRoom->setAdjacent(kitchen, NULL, NULL, commonArea, NULL);
	bathRoom->setAdjacent(masterBedRoom, NULL, NULL, NULL, NULL);
	kitchen->setAdjacent(NULL, diningRoom, NULL, livingRoom, NULL);
	laundryRoom->setAdjacent(commonArea, NULL, NULL, NULL, NULL);
	
	currentLoc = commonArea;
		
	bag = new Container;
	this->bag->setContainerName("bag");
	this->bag->setMaxWeight(40);
	}

/*********************************************************************
Game::play
a default constructor for Game 
*********************************************************************/
void Game::play()
{
	Room* destination;
	std::cout << "\nYou are the lone visitor of Pittock Mansion in Portland around 3 pm in a slow Monday afternoon. As a Pok Pok chef, Mr. Pittock ghost has trapped you until he can eat your best dish. You need to cook chicken wings for Mr. Pittock. You first need to make a phone call in the living room. (Please refer to the cheat sheet PDF file for walkthrough of the game)\n";
	start = time(0);
	while (currentLoc !=  outside)
	{
		while (!isTimeUp)
		{
			isvalid = false;
			while (!isvalid)
			{
				end = time(0);		
				timeRemain = timeRemain - difftime(end,start)*0.1;
				if (timeRemain <= 0)
				{
					isTimeUp = true;
					}
				start = end;
				std::cout << "\ntime: " << timeRemain << " minutes until Mr. Pittock is too hungry" << std::endl;
				choice = currentLoc->enter();	
				if (choice == 1)
				{
					item = currentLoc->explore();	
					if (item != NULL)
					{
						bag->addItem(item);
						bag->displayItem();
						}
					}
				else if (choice == 2)
				{
					
					currentLoc->interact(bag);
					
					}
				else if (choice == 3 )
				{
					destination = currentLoc->changeRoom();
					if (destination == outside)
					{
						numItem = bag->getNumItem();
						outside->interact(bag);
						if (bag->getNumItem() != numItem)
						{
							currentLoc = outside;
							isTimeUp = true;
							}
						}				
					else
					{
						currentLoc = destination;
						}
					isvalid = true;
					}
				else if (choice == 4)
				{
					currentLoc = outside;
					isvalid = true;
					isTimeUp = true;
					}
				}// end while !valid
			} // end while !isTimeUp
		if (isTimeUp && timeRemain <= 0) 
		{
			std::cout << "\nMr. Pittock is too hungry and has trapped you forever!!\n";
			currentLoc = outside;
			}
		}// end while
	}

/*********************************************************************
Game::Game
a default constructor for Game 
*********************************************************************/
Game::~Game()
{
	delete commonArea;
	delete livingRoom;
	delete outside;
	delete masterBedRoom;
	delete kitchen;
	delete bathRoom;
	delete diningRoom;
	delete laundryRoom;
	delete bag;
	
	
	}