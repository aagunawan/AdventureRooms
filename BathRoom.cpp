/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains BathRoom Class Implementation
*********************************************************************/

#include "BathRoom.h"

/*********************************************************************
BathRoom::BathRoom
a default constructor for BathRoom that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

BathRoom::BathRoom() 
{
	this->roomName = "BathRoom";
	
	this->window.setContainerName("window");
	this->window.setMaxWeight(15);
	}
	

/*********************************************************************
BathRoom::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void BathRoom::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}

/*********************************************************************
BathRoom::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* BathRoom::explore()
{
	Item* newItem = NULL;
	std::cout << "\n There is nothing to explore here \n";
	return newItem;
	delete newItem;

	

	} // end void explore

/*********************************************************************
BathRoom::interact

*********************************************************************/
void BathRoom::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	Item* itemToThrow;
	
	//bag->displayItem();

	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to do?\n";		
		std::cout << "1. Open the window\n";
		std::cout << "2. Throw an item through the window\n";	
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
        	if (choice >= 1 && choice <= 2)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 2\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			if (!window.getContainerState()) // if window is closed
			{
				window.setContainerState(true); // window is now open
				std::cout << "\nThe window is now open\n";
				}// end if (!window.getContainerState())	
			else 
			{
				std::cout << "\nThe window is already open\n";
				}						
			} // end if choice 1
		else if (choice == 2)
		{
			if (window.getContainerState()) // if window is open you can throw things
			{		
				valid = false;
				while(! valid)
				{ // repeat as long as the input is not valid
					std::cout << "Please enter the item from bag you want to throw: (1 - " << bag->getNumItem() << ")\n";		
					bag->displayItem();	
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
						if (choice >=1 && choice <= bag->getNumItem())
						{							
							itemToThrow = bag->getItemList().at(choice-1);
							bag->removeItem(itemToThrow->getItemName());
							std::cout << "You have thrown " << itemToThrow->getItemName() << " !!\n";
							if (itemToThrow->getItemName() == "fence key")
							{
								setFenceKeyStatus(true); // fence key for accessing dumbwaiter is outside
								std::cout << "\nThe fence for accessing dumbwaiter from outside is unlocked and you can collect your items from the laundry room.\n";
								}
							
							valid = true;
							}
						else if (choice == 0)
						{
							valid = true;
							}
						else 
						{
							std::cout << "Enter a number between 1 and " <<  bag->getNumItem()<< "\n\n";
							}
						}
					} // end while (!valid)
				
				} // if (dumbwaiter.getWeight() == 0 )

			} // end if choice 2
		} // end while valid
	//delete itemToThrow;
	}


/*********************************************************************
BathRoom::BathRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* BathRoom::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go to master bedroom\n";
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
        	if (choice == 1)
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
		} // end while !valid
	} // end void explore

/*********************************************************************
BathRoom::~BathRoom
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

BathRoom::~BathRoom() 
{
	}
