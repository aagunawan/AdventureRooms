/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Outside Class Implementation
*********************************************************************/

#include "Outside.h"

/*********************************************************************
Outside::Outside
a default constructor for Outside that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

Outside::Outside() 
{
	this->roomName = "Outside";
	}
	

/*********************************************************************
Outside::setFront
method to assign the adjacent pointer room
*********************************************************************/

void Outside::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}

	
/*********************************************************************
Outside::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* Outside::explore()
{
	Item* newItem;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "The door is locked. Do you have the main gate key? (y/n)\n";		
		std::cout << "Your choice: ";	
        std::cin >> answer;

		if (answer == 'y')
		{	
			return newItem;
			valid = true;
			}
		else if (answer == 'n')
		{
			valid = true;
			}     
		} // end while !valid
	} // end void explore
	
/*********************************************************************
Outside::interact

*********************************************************************/
void Outside::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	//std::cout << "Your items in the bag are: \n";
	bag->displayItem();
	std::cout << "Please enter the item from bag to unlock main gate: (1 - " << bag->getNumItem() << ")\n";		
	std::cout << "Your choice: ";	
	std::cin >> choice;
	

	if (bag->getItemList().at(choice-1)->getItemName() == "main gate key")
	{
		bag->removeItem("main gate key");
		std::cout << "You are outside and free\n\n";
		}
	
	else 
	{
		std::cout << "The main gate key is not in your bag\n\n";
		}

	
	/*
	for (index = 0; index < bag->getNumItem(); index++)
	{
		if (bag->getItemList().at(index)->getItemName() == itemName)
		{
			if (bag->getItemList().at(index)->getItemName() == "Main Gate Key")
			{
				std::cout << "You are outside and free\n\n";
				}
			} // end (bag.at(index)->getItemName() == answer)
		else 
		{
			std::cout << "The main gate key is not in your bag\n\n";
			}
		}
		*/
	}
	

/*********************************************************************
Outside::changeRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* Outside::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "Which room do you want to go to?\n";
		std::cout << "1. Go to living room\n";
		std::cout << "2. Go to dining room\n";
		std::cout << "3. Go to master bedroom\n";
		std::cout << "4. Go up to laundry room\n";
		std::cout << "5. Go outside and get freedom\n";
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
        	if (choice >= 1 && choice <= 5)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 5\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			return this->front;
			} // end if choice 1
		else if (choice == 2)
		{
			return this->back;
			} // end if choice 1
		} // end while !valid
	} // end void explore

/*********************************************************************
CommonArea::~CommonArea
a default constructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

Outside::~Outside() 
{

	}
