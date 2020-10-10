/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Room Class Implementation
*********************************************************************/

#include "Room.h"

/*********************************************************************
Room::Room
a default constructor for Room that initializes the Room pointer to 
NULL.
*********************************************************************/
Room::Room()
{
	this->front = NULL;
	this->back = NULL;
	this->left = NULL;
	this->right = NULL;
	this->roomName = "";
	
	
	
	}

/*********************************************************************
Room::enter
enter function for common area : allows to explore or move to diff rooms
*********************************************************************/
int Room::enter()
{
	
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nYou are in the " <<  this->roomName << ".\n";
		std::cout << "What would you like to do?\n";
		std::cout << "1. Search the room for items\n";
		std::cout << "2. Use and remove item from bags\n";
		std::cout << "3. Go to a different room\n";
		std::cout << "4. Quit the game\n";
		std::cout << "Your choice: ";
        std::cin >> choice;
        
        if(std::cin.fail())
        {
            std::cout << "Wrong input" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(256, '\n');
            
        	}
        else 
        {
        	if (choice >= 1 && choice <= 4)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 3\n\n";
    	  		}
        	}
    	} // end while !valid
    
    return choice;
	} // end void enter

/*********************************************************************
Room::getRoomName

*********************************************************************/
std::string Room::getRoomName()
{
	return this->roomName;
	}

/*********************************************************************
Room::getFenceKeyStatus

*********************************************************************/
bool Room::getFenceKeyStatus()
{
	return this->isFenceKeyOut;
	}

/*********************************************************************
Room::setFenceKeyStatus

*********************************************************************/
void Room::setFenceKeyStatus(bool status)
{
	this->isFenceKeyOut = status;
	}

/*********************************************************************
Room::getFenceKeyStatus

*********************************************************************/
bool Room::getChickenOrderStatus()
{
	return this->isChickenOrdered;
	}

/*********************************************************************
Room::setFenceKeyStatus

*********************************************************************/
void Room::setChickenOrderStatus(bool status)
{
	this->isChickenOrdered = status;
	}

/*********************************************************************
Room::getFront

*********************************************************************/
Room* Room::getFront()
{
	return this->front;
	}


/*********************************************************************
Room::~Room
a destructor for Room 
*********************************************************************/

Room::~Room()
{

	}
	
	