/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Room Class Implementation
*********************************************************************/

#include "LivingRoom.h"

/*********************************************************************
LivingRoom::LivingRoom
a default constructor for Living Room that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

LivingRoom::LivingRoom() 
{
	this->roomName = "Living Room";
	remoteControl = new Item;
	wirelessPhone = new Item;	
	charger = new Item;
	
	this->remoteControl->setItemName("remote control");
	this->remoteControl->setItemWeight(3);	
	this->wirelessPhone->setItemName("wireless phone");
	this->wirelessPhone->setItemWeight(3);
	this->charger->setItemName("charger");
	this->charger->setItemWeight(5);
	
	this->TV.setContainerName("TV");
	this->TV.setMaxWeight(20);
	this->couch.setContainerName("couch");
	this->couch.setMaxWeight(60);
	this->cabinet.setContainerName("cabinet");
	this->cabinet.setMaxWeight(50);
	this->table.setContainerName("table");
	this->table.setMaxWeight(15);
	
	this->TV.addItem(remoteControl);
	this->couch.addItem(wirelessPhone);
	this->cabinet.addItem(charger);
	}

/*********************************************************************
LivingRoom::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void LivingRoom::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}
/*********************************************************************
LivingRoom::explore
explore function for living room : allows to explore room
*********************************************************************/
Item* LivingRoom::explore()
{
	Item* newItem = NULL;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to explore?\n";		
		std::cout << "1. Look underneath the TV\n";
		std::cout << "2. Flip the couch\n";
		std::cout << "3. Open the cabinet\n";		
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
			TV.displayItem();
			
			
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
					if (choice >=1 && choice <= TV.getNumItem())
					{							
						newItem = TV.getItemList().at(choice-1);						
						TV.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  TV.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		else if (choice == 2)
		{
			couch.displayItem();
			
			
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
					if (choice >=1 && choice <= couch.getNumItem())
					{							
						newItem = couch.getItemList().at(choice-1);						
						couch.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  couch.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2
		
		else if (choice == 3)
		{
			cabinet.displayItem();
			
			
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
					if (choice >=1 && choice <= cabinet.getNumItem())
					{							
						newItem = cabinet.getItemList().at(choice-1);						
						cabinet.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  cabinet.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 3

		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore

/*********************************************************************
LivingRoom::interact

*********************************************************************/
void LivingRoom::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	//bag->displayItem();

	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to do?\n";		
		std::cout << "1. Use the power outlet to charge the phone\n";
		std::cout << "2. Make a phone call\n";	
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
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nYou will need a wireless phone and a charger.\n";
				bag->displayItem();
				std::cout << "Please first enter the charger: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "charger")
						{
							std::cout << "Now you need the phone, please enter it: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
							std::cout << "Your choice: ";	
							std::cin >> choice;
							if (bag->getItemList().at(choice-1)->getItemName() == "wireless phone")
							{
								bag->removeItem("wireless phone");
								bag->removeItem("charger");
								table.addItem(wirelessPhone);
								table.addItem(charger);
								wirelessPhone->setItemState(true); // phone is charged
								std::cout << "Now the phone is charged and on the table. You can make a phone call!!\n";
								}
							}	
						else 
						{
							std::cout << "You did not enter a charger\n";
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
		else if (choice == 2)
		{
			if (!wirelessPhone->getItemState())
			{
				std::cout << "Your phone is not charged!\n";
				}
			else
			{
				std::cout << "You have ordered chicken wings and their ingredients. Somebody will deliver it. But you need to pick it up through the dumbwaiter in the laundry room! However, first go to the master bedroom to collect fence and dumbwaiter key. The fence key needs to be thrown from bathroom to outside.\n";
				setChickenOrderStatus(true);
				/*
				chickenWings->setItemState(true); // chicken wings are ordered;
				soySauce->setItemState(true); // chicken wings are ordered;
				oil->setItemState(true); // chicken wings are ordered;
				ginger->setItemState(true); // chicken wings are ordered;
				salt->setItemState(true); // chicken wings are ordered;
				pepper->setItemState(true); // chicken wings are ordered;
				*/
				}

			} // end if choice 1
		} // end while valid
	}

/*********************************************************************
LivingRoom::changeRoom
change Room function for living room : allows to move to diff rooms
*********************************************************************/
Room* LivingRoom::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?.\n";
		std::cout << "1. Go back to common area\n";
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
        	if (choice ==1)
			{	
    	   		valid = true;
    	  		 }
    	  	else 
    	  	{
    	  		std::cout << "You can only go back to common area\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			return this->back;
			} // end if choice 1
		} // end while !valid
	} // end void explore

/*********************************************************************
LivingRoom::~LivingRoom
a default destructor for living room that initializes the Room pointer to 
according to the configurations
*********************************************************************/

LivingRoom::~LivingRoom() 
{
	delete wirelessPhone;
	delete remoteControl;
	delete charger;
	}
