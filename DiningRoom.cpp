/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains DiningRoom Class Implementation
*********************************************************************/

#include "DiningRoom.h"

/*********************************************************************
DiningRoom::DiningRoom
a default constructor for MasterBedRoom that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

DiningRoom::DiningRoom() 
{
	this->roomName = "Dining Room";
	
	mainGateKey = new Item;
	
	this->mainGateKey->setItemName("main gate key");
	this->mainGateKey->setItemWeight(2);	
	
	this->plate.setContainerName("plate");
	this->plate.setMaxWeight(20);
	this->tableRunner.setContainerName("table runner");
	this->tableRunner.setMaxWeight(10);
	this->chair.setContainerName("chair");
	this->chair.setMaxWeight(50);
	
	this->tableRunner.addItem(mainGateKey);
	}
	

/*********************************************************************
DiningRoom::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void DiningRoom::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}

/*********************************************************************
DiningRoom::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* DiningRoom::explore()
{
	Item* newItem = NULL;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nIf Mr. Pittock is no longer hungry, you can collect the main gate key\n";		
		std::cout << "1. Lift the table runner\n";
		std::cout << "2. Look underneath the chair\n";		
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
			tableRunner.displayItem();		
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
					if (choice >=1 && choice <= tableRunner.getNumItem())
					{							
						if (plate.getContainerState())
						{					
							newItem = tableRunner.getItemList().at(choice-1);						
							tableRunner.removeItem(newItem->getItemName());
							}
						else
						{
							std::cout << "\nMr. Pittock has not eaten the chicken wings yet\n";
							}
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
						std::cout << "Enter a number between 1 and " <<  tableRunner.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		if (choice == 2)
		{
			chair.displayItem();		
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
					if (choice >=1 && choice <= chair.getNumItem())
					{							
						newItem = chair.getItemList().at(choice-1);						
						chair.removeItem(newItem->getItemName());
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
						std::cout << "Enter a number between 1 and " <<  chair.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2
		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore

/*********************************************************************
DiningRoom::interact

*********************************************************************/
void DiningRoom::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	bool isvalid;
	
	//bag->displayItem();

	isvalid = false;
    while(! isvalid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to do?\n";		
		std::cout << "1. Serve food for Mr. Pittock\n";
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
        	if (choice >= 1 && choice <= 1)
			{	
    	   		isvalid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 1\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nYou will need a cooked chicken.\n";
				bag->displayItem();
				std::cout << "Please enter the cooked chicken: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						
						
						
						if (bag->getItemList().at(choice-1)->getItemName() == "cooked chicken")
						{						
							plate.addItem(bag->removeItem("cooked chicken"));
							plate.setContainerState(true);
							std::cout << "Mr. Pittock has now been fed. You can grab the main gat key under the table runner\n";
							}

						else 
						{
							std::cout << "You did not enter cooked chicken\n";
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
			} // end if choice 1
		} // end while !isvalid
	}
/*********************************************************************
DiningRoom::changeRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* DiningRoom::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go to kitchen\n";
		std::cout << "2. Go back to common area\n";
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
			return this->left;
			} // end if choice 1
		} // end while !valid
	} // end void explore

/*********************************************************************
DiningRoom::~DiningRoom
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

DiningRoom::~DiningRoom() 
{
	delete mainGateKey;
	}
