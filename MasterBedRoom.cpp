/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains MasterBedRoom Class Implementation
*********************************************************************/

#include "MasterBedRoom.h"

/*********************************************************************
MasterBedRoom::MasterBedRoom
a default constructor for MasterBedRoom that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

MasterBedRoom::MasterBedRoom() 
{
	this->roomName = "Master Bed Room";
	dumbwaiterKey = new Item;
	shirt = new Item;	
	fenceKey = new Item;
	
	this->dumbwaiterKey->setItemName("dumbwaiter key");
	this->dumbwaiterKey->setItemWeight(2);	
	this->shirt->setItemName("shirt");
	this->shirt->setItemWeight(3);
	this->fenceKey->setItemName("fence key");
	this->fenceKey->setItemWeight(2);
	
	this->bed.setContainerName("bed");
	this->bed.setMaxWeight(30);
	this->dresser.setContainerName("dresser");
	this->dresser.setMaxWeight(20);
	
	this->bed.addItem(dumbwaiterKey);
	this->dresser.addItem(shirt);
	this->dresser.addItem(fenceKey);
	}
	

/*********************************************************************
MasterBedRoom::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void MasterBedRoom::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}
	
/*********************************************************************
MasterBedRoom::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* MasterBedRoom::explore()
{
	Item* newItem= NULL;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to explore?\n";		
		std::cout << "1. Open the dresser\n";
		std::cout << "2. Lift the bed\n";	
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
			dresser.displayItem();		
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "Enter the item number you want to add (or 0 if you do not want to add an item)\n";
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
					if (choice >=1 && choice <= dresser.getNumItem())
					{							
						newItem = dresser.getItemList().at(choice-1);						
						dresser.removeItem(newItem->getItemName());
						valid = true;
						}
					else if (choice == 0)
					{
						valid = true;
						return NULL;
						std::cout << "No item added\n\n";
						}
					else 
					{
						std::cout << "Enter a number between 1 and " <<  dresser.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		else if (choice == 2)
		{
			//std::cout << "\nThe available items in " << laundryMachine.getContainerName() << " are\n";
			bed.displayItem();
			
			
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "Enter the item number you want to add (or 0 if you do not want to add an item)\n";
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
					if (choice >=1 && choice <= bed.getNumItem())
					{							
						newItem = bed.getItemList().at(choice-1);						
						bed.removeItem(newItem->getItemName());	
						valid = true;
						}
					else if (choice == 0)
					{
						valid = true;
						return NULL;
						std::cout << "No item added\n\n";
						}
					else 
					{
						std::cout << "Enter a number between 1 and " <<  bed.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2		
		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore
	
/*********************************************************************
MasterBedRoom::interact

*********************************************************************/
void MasterBedRoom::interact(Container *bagIn)
{
	std::cout << "\nThere is nothing to interact in here\n";
	}

/*********************************************************************
MasterBedRoom::changeRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* MasterBedRoom::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go back to common area\n";
		std::cout << "2. Go to bath room\n";
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
			return this->front;
			} // end if choice 1
		else if (choice == 2)
		{
			return this->back;
			} // end if choice 1
		} // end while !valid
	} // end void explore

/*********************************************************************
MasterBedRoom::~MasterBedRoom
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

MasterBedRoom::~MasterBedRoom() 
{
	delete shirt;
	delete fenceKey;
	delete dumbwaiterKey;
	}
