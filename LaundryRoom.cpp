/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains laundryRoom Class Implementation
*********************************************************************/

#include "LaundryRoom.h"

/*********************************************************************
laundryRoom::laundryRoom
a default constructor for BathRoom that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

LaundryRoom::LaundryRoom() 
{
	this->roomName = "Laundry Room";
	stickyNote = new Item;
	towel = new Item;	
	
	chickenWings = new Item;
	pepper = new Item;
	salt = new Item;
	oil = new Item;
	ginger = new Item;
	soySauce = new Item;
	
	this->stickyNote->setItemName("sticky note");
	this->stickyNote->setItemWeight(1);	
	this->towel->setItemName("towel");
	this->towel->setItemWeight(2);

	this->chickenWings->setItemName("chicken wings");
	this->chickenWings->setItemWeight(10);
	
	
	this->pepper->setItemName("pepper");
	this->pepper->setItemWeight(1);
	
	this->salt->setItemName("salt");
	this->salt->setItemWeight(1);
	
	this->oil->setItemName("oil");
	this->oil->setItemWeight(2);

	this->ginger->setItemName("ginger");
	this->ginger->setItemWeight(1);
	
	this->soySauce->setItemName("soy sauce");
	this->soySauce->setItemWeight(2);
	
	this->door.setContainerName("door");
	this->door.setMaxWeight(10);
	this->dumbwaiter.setContainerName("dumbwaiter");
	this->dumbwaiter.setMaxWeight(20);
	this->laundryMachine.setContainerName("laundry machine");
	this->laundryMachine.setMaxWeight(25);

	this->door.addItem(stickyNote);
	this->laundryMachine.addItem(towel);
	}
	

/*********************************************************************
laundryRoom::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void LaundryRoom::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}

	
/*********************************************************************
laundryRoom::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* LaundryRoom::explore()
{
	Item* newItem= NULL;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to explore?\n";		
		std::cout << "1. Read a sticky note on the door\n";
		std::cout << "2. Open the laundry machine\n";	
		std::cout << "3. Collect items from the dumbwaiter\n";	
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
        	if (choice >= 1 && choice <= 3)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 3\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			//std::cout << "\nThe available items in " << pictures.getContainerName() << " are\n";
			door.displayItem();
			
			
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "Enter the item number you want to add (or 0 if you do not want to add an item)\n";
				std::cout << "Your choice: ";
				std::cin >> choice;
		
				if(std::cin.fail())
				{
					std::cout << "\nWrong input" << std::endl;
					std::cin.clear(); 
					std::cin.ignore(256, '\n');		
				}
				else 
				{
					if (choice >=1 && choice <= door.getNumItem())
					{							
						newItem = door.getItemList().at(choice-1);						
						door.removeItem(newItem->getItemName());
						std::cout << "\nThe key to access dumbwaiter is located in the master bedroom\n";	
						valid = true;
						}
					else if (choice == 0)
					{
						valid = true;
						return NULL;
						std::cout << "\nNo item added\n\n";
						}
					else 
					{
						std::cout << "\nEnter a number between 1 and " <<  door.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		else if (choice == 2)
		{
			//std::cout << "\nThe available items in " << laundryMachine.getContainerName() << " are\n";
			laundryMachine.displayItem();
			
			
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nEnter the item number you want to add (or 0 if you do not want to add an item)\n";
				std::cout << "Your choice: ";
				std::cin >> choice;
		
				if(std::cin.fail())
				{
					std::cout << "\nWrong input" << std::endl;
					std::cin.clear(); 
					std::cin.ignore(256, '\n');		
				}
				else 
				{
					if (choice >=1 && choice <= laundryMachine.getNumItem())
					{							
						newItem = laundryMachine.getItemList().at(choice-1);						
						laundryMachine.removeItem(newItem->getItemName());	
						valid = true;
						}
					else if (choice == 0)
					{
						valid = true;
						return NULL;
						std::cout << "\nNo item added\n\n";
						}
					else 
					{
						std::cout << "Enter a number between 1 and " <<  laundryMachine.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2
		else if (choice == 3)
		{
			//std::cout << "\nThe available items in " << laundryMachine.getContainerName() << " are\n";
			if (!dumbwaiter.getContainerState()) // if dumbwaiter is on the laundry room level
			{
				dumbwaiter.displayItem();
			
			
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
						if (choice >=1 && choice <= dumbwaiter.getNumItem())
						{							
							newItem = dumbwaiter.getItemList().at(choice-1);						
							dumbwaiter.removeItem(newItem->getItemName());	
							valid = true;
							}
						else if (choice == 0)
						{
							valid = true;
							return NULL;
							std::cout << "\nNo item added\n\n";
							}
						else 
						{
							std::cout << "Enter a number between 1 and " <<  dumbwaiter.getNumItem()<< "\n\n";
							}
						}
					} // end while (!valid)
				} //if (!dumbWaiter.getContainerState())
				else 
				{
					std::cout << "\nThe dumbwaiter is downstairs!!\n";
					}
			} // end if choice 3

		
		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore

/*********************************************************************
LaundryRoom::interact

*********************************************************************/
void LaundryRoom::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	//bag->displayItem();

	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to do?\n";		
		std::cout << "1. Bring the dumbwaiter down\n";
		std::cout << "2. Bring the dumbwaiter up\n";
		std::cout << "3. Shout to ask the delivery man to put the ordered chicken and ingredients\n";		
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
        	if (choice >= 1 && choice <= 3)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "Enter a number between 1 and 3\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			if (dumbwaiter.getWeight() == 0 )
			{
				valid = false;
				while(! valid)
				{ // repeat as long as the input is not valid
					std::cout << "\nYou will need a key to operate the dumbwaiter.\n";
					bag->displayItem();
					std::cout << "Please enter the dumbwaiter key: (1 - " << bag->getNumItem() << ") (or 0 if you do not want to add an item)\n";		
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
							if (bag->getItemList().at(choice-1)->getItemName() == "dumbwaiter key")
							{
								//bag->removeItem("dumbwaiter key");
								dumbwaiter.addItem(bag->removeItem("dumbwaiter key"));
								dumbwaiter.setContainerState(true); // dumbwaiter is downstairs
								std::cout << "The dumbwaiter is now downstairs!!\n";
								/*
								if (chickenWings->getItemState()&& getFenceKeyStatus())
								{
								
									dumbwaiter.addItem(chickenWings);
									dumbwaiter.addItem(oil);
									dumbwaiter.addItem(salt);
									dumbwaiter.addItem(pepper);
									dumbwaiter.addItem(soySauce);
									dumbwaiter.addItem(ginger);
									chickenWings->setItemState(false);
									oil->setItemState(false);
									pepper->setItemState(false);
									salt->setItemState(false);
									ginger->setItemState(false);
									soySauce->setItemState(false);
															
									}
									*/
								}
							else 
							{
								std::cout << "You did not enter the correct key\n";
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
				else if(dumbwaiter.getWeight() > 0 && dumbwaiter.getItemList().at(0)->getItemName() == "dumbwaiter key" )
				{
					dumbwaiter.setContainerState(true); // dumbwaiter is downstairs
					std::cout << "The dumbwaiter is now downstairs!!\n";
					/*
					if (chickenWings->getItemState() && getFenceKeyStatus())
					{
						
						dumbwaiter.addItem(chickenWings);
						dumbwaiter.addItem(oil);
						dumbwaiter.addItem(salt);
						dumbwaiter.addItem(pepper);
						dumbwaiter.addItem(soySauce);
						dumbwaiter.addItem(ginger);
						chickenWings->setItemState(false);
						oil->setItemState(false);
						pepper->setItemState(false);
						salt->setItemState(false);
						ginger->setItemState(false);
						soySauce->setItemState(false);
					
						}
						*/
				}// end if (dumbwaiter.getItemList().at(0)->getItemName == "dumbwaiter key" 							
			} // end if choice 1
		else if (choice == 2)
		{
			if (dumbwaiter.getWeight() == 0 )
			{
				valid = false;
				while(! valid)
				{ // repeat as long as the input is not valid
					std::cout << "\nYou will need a key to operate the dumbwaiter.\n";
					bag->displayItem();
					std::cout << "Please enter the dumbwaiter key: (1 - " << bag->getNumItem() << ") (or 0 if you do not want to add an item)\n";		
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
							if (bag->getItemList().at(choice-1)->getItemName() == "dumbwaiter key")
							{
								//bag->removeItem("dumbwaiter key");
								dumbwaiter.addItem(bag->removeItem("dumbwaiter key"));
								dumbwaiter.setContainerState(false); // dumbwaiter is here
								std::cout << "The dumbwaiter is now here!!\n";
								}	
							else 
							{
								std::cout << "You did not enter the correct key\n";
								}
							valid = true;
							}
						else if (choice == 0)
						{
							valid = true;
							}
						else 
						{
							std::cout << "Enter a number between 1 and " <<  bag->getNumItem()<< " (or 0 if you do not want to add an item)\n\n";
							}
						}
					} // end while (!valid)			
				} // if (dumbwaiter.getWeight() == 0 )
				else if(dumbwaiter.getWeight() > 0 && dumbwaiter.getItemList().at(0)->getItemName() == "dumbwaiter key" )
				{
					dumbwaiter.setContainerState(false); // dumbwaiter is here
					std::cout << "The dumbwaiter is now here!!\n";
				}// end if (dumbwaiter.getItemList().at(0)->getItemName == "dumbwaiter key" 
			} // end if choice 2
		if (choice == 3)
		{
			if (dumbwaiter.getWeight() != 0 && dumbwaiter.getContainerState() && Room::getChickenOrderStatus() && Room::getFenceKeyStatus())
			{
				dumbwaiter.addItem(chickenWings);
				dumbwaiter.addItem(oil);
				dumbwaiter.addItem(salt);
				dumbwaiter.addItem(pepper);
				dumbwaiter.addItem(soySauce);
				dumbwaiter.addItem(ginger);
				dumbwaiter.displayItem();
				}	
			else
			{
				std::cout << "\nEither dumbwaiter is not down or chicken is not ordered or fence is not open yet or order is already in the dumbwaiter\n";
				}			
			} // end if choice 3
		} // end while valid
	}



/*********************************************************************
LaundryRoom::LaundryRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* LaundryRoom::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go down to common area\n";
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
    	  		std::cout << "Enter a number between 1 and 1\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			return this->front;
			} // end if choice 1

		} // end while !valid
	} // end void explore

/*********************************************************************
LaundryRoom::~LaundryRoom
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

LaundryRoom::~LaundryRoom() 
{
	delete stickyNote;
	delete towel;
		delete chickenWings;
	delete soySauce;
	delete ginger;
	delete salt;
	delete pepper;
	delete oil;
	}
