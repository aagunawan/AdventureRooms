/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Common Area Class Implementation
*********************************************************************/

#include "CommonArea.h"

/*********************************************************************
CommonArea::CommonArea
a default constructor for Common Area that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

CommonArea::CommonArea() 
{
	this->roomName = "Common Area";
	this->up = NULL;
	
	letter = new Item;
	pin = new Item;	
	
	this->letter->setItemName("letter");
	this->letter->setItemWeight(1);	
	this->pin->setItemName("pin");
	this->pin->setItemWeight(2);
	
	this->rug.setContainerName("rug");
	this->rug.setMaxWeight(50);
	this->pictures.setContainerName("pictures");
	this->pictures.setMaxWeight(42);
	
	this->rug.addItem(pin);
	this->pictures.addItem(letter);
	}
	

/*********************************************************************
CommonArea::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void CommonArea::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	this->up = up;
	}
	
/*********************************************************************
CommonArea::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* CommonArea::explore()
{
	Item* newItem= NULL;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to explore?\n";		
		std::cout << "1. Look behind the hanging pictures\n";
		std::cout << "2. Search under the rug\n";	
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
			//std::cout << "\nThe available items in " << pictures.getContainerName() << " are\n";
			pictures.displayItem();
			
			
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
					if (choice >=1 && choice <= pictures.getNumItem())
					{							
						newItem = pictures.getItemList().at(choice-1);						
						pictures.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  pictures.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		else if (choice == 2)
		{
			std::cout << "There is a pin underneath the rug\n";
			std::cout << "Do you want to take it? (y/n)";
			std::cout << "Your answer: ";
			std::cin >> answer;
			//std::cin.ignore();
			//std::getline(std::cin, answer);
			if (answer == 'y')
			{
			 	}
			else if (answer == 'n')
			{
			 	}
			} // end if choice 2

		
		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore

/*********************************************************************
CommonArea::interact

*********************************************************************/
void CommonArea::interact(Container *bagIn)
{
	std::cout << "\nThere is nothing to interact in here\n";
	}

/*********************************************************************
CommonArea::changeRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* CommonArea::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go to living room\n";
		std::cout << "2. Go to master bedroom\n";
		std::cout << "3. Go to dining room\n";
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
		} // end while !valid
		if (choice == 1)
		{
			return this->front;
			} // end if choice 1
		else if (choice == 2)
		{
			return this->back;
			} // end if choice 2
		else if (choice == 3)
		{
			return this->right;
			} // end if choice 3
		else if (choice == 4)
		{
			return this->up;
			} // end if choice 4
		else if (choice == 5)
		{
			return this->left;
			} // end if choice 5
	} // end void explore

/*********************************************************************
CommonArea::~CommonArea
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

CommonArea::~CommonArea() 
{
	delete letter;
	delete pin;
	}
