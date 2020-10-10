/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Kitchen Class Implementation
*********************************************************************/

#include "Kitchen.h"

/*********************************************************************
Kitchen::Kitchen
a default constructor for MasterBedRoom that initializes the room name,
items available in the room, as well as containers containing the items
*********************************************************************/

Kitchen::Kitchen() 
{
	this->roomName = "Kitchen";
	
	knife = new Item;
	cuttingBoard = new Item;	
	deepFryer = new Item;
	bowl = new Item;
	cookedChicken = new Item;
	
	this->mixerCounter = 0;
	this->knife->setItemName("knife");
	this->knife->setItemWeight(2);	
	this->cuttingBoard->setItemName("cutting board");
	this->cuttingBoard->setItemWeight(3);
	this->deepFryer->setItemName("deep fryer");
	this->deepFryer->setItemWeight(5);
	this->bowl->setItemName("bowl");
	this->bowl->setItemWeight(3);
	this->cookedChicken->setItemName("cooked chicken");
	this->cookedChicken->setItemWeight(5);
	
	this->cabinet1.setContainerName("cabinet 1");
	this->cabinet1.setMaxWeight(30);
	this->cabinet2.setContainerName("cabinet 2");
	this->cabinet2.setMaxWeight(20);
	this->drawer.setContainerName("drawer");
	this->drawer.setMaxWeight(10);
	this->countertop.setMaxWeight(100);
	this->countertop.setContainerName("countertop");
	
	this->cabinet1.addItem(cuttingBoard);
	this->cabinet1.addItem(deepFryer);
	this->cabinet2.addItem(bowl);
	this->drawer.addItem(knife);
	}
	

/*********************************************************************
Kitchen::setAdjacent
method to assign the adjacent pointer room
*********************************************************************/

void Kitchen::setAdjacent(Room* front, Room* back, Room* right, Room* left, Room* up)
{
	this->front = front;
	this->back = back;
	this->right = right;
	this->left = left;
	}

/*********************************************************************
Kitchen::explore
explore function for common area : allows to explore room and collect
items
*********************************************************************/
Item* Kitchen::explore()
{
	Item* newItem= NULL;
	//newItem = new Item;
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to explore?\n";		
		std::cout << "1. Open cabinet 1\n";
		std::cout << "2. Open cabinet 2\n";
		std::cout << "3. Open drawer\n";		
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
    	  		std::cout << "Enter a number between 1 and 2\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			cabinet1.displayItem();		
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
					if (choice >=1 && choice <= cabinet1.getNumItem())
					{							
						newItem = cabinet1.getItemList().at(choice-1);						
						cabinet1.removeItem(newItem->getItemName());
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
						std::cout << "Enter a number between 1 and " <<  cabinet1.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 1
		else if (choice == 2)
		{
			//std::cout << "\nThe available items in " << laundryMachine.getContainerName() << " are\n";
			cabinet2.displayItem();
			
			
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
					if (choice >=1 && choice <= cabinet2.getNumItem())
					{							
						newItem = cabinet2.getItemList().at(choice-1);						
						cabinet2.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  cabinet2.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2
		else if (choice == 3)
		{
			drawer.displayItem();			
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
					if (choice >=1 && choice <= drawer.getNumItem())
					{							
						newItem = drawer.getItemList().at(choice-1);						
						drawer.removeItem(newItem->getItemName());	
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
						std::cout << "Enter a number between 1 and " <<  drawer.getNumItem()<< "\n\n";
						}
					}
				} // end while (!valid)
			} // end if choice 2			
		} // end while !valid
		return newItem;
		delete newItem;
	} // end void explore
	

/*********************************************************************
Kitchen::interact

*********************************************************************/
void Kitchen::interact(Container *bagIn)
{
	Container* bag;
	bag = bagIn;
	Item* itemToCut;
	bool isvalid;
	
	//bag->displayItem();

	isvalid = false;
    while(! isvalid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhat do you want to do?\n";		
		std::cout << "1. Cut the ginger\n";
		std::cout << "2. Mix the ingredients with chicken\n";	
		std::cout << "3. Cook the chicken\n";	
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
    	   		isvalid = true;
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
				std::cout << "\nYou will need a knife.\n";
				bag->displayItem();
				std::cout << "Please enter the knife: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						
						
						
						if (bag->getItemList().at(choice-1)->getItemName() == "knife")
						{
							
							countertop.addItem(bag->removeItem("knife"));
							}

						else 
						{
							std::cout << "You did not enter knife\n";
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
		
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nYou will need a cutting board.\n";
				bag->displayItem();
				std::cout << "Please enter the cutting board: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "cutting board")
						{
							std::cout << "Now you need the ginger, please enter it: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
							std::cout << "Your choice: ";	
							std::cin >> choice;
							if (bag->getItemList().at(choice-1)->getItemName() == "ginger")
							{
								
								itemToCut = bag->removeItem("ginger");
								countertop.addItem(bag->removeItem("cutting board"));
								itemToCut->setItemState(true); // ginger is cut and put back in the bag
								bag->addItem(itemToCut);
								std::cout << "The ginger has been cut and put back in the bag!!\n";
								//std::cout << "Ginger state " << itemToCut->getItemState() << std::endl;
								}
							}	
						else 
						{
							std::cout << "You did not enter the correct item\n";
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
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nYou will need a bowl.\n";
				bag->displayItem();
				std::cout << "Please first enter the bowl: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
								
						if (bag->getItemList().at(choice-1)->getItemName() == "bowl")
						{
							
							countertop.addItem(bag->removeItem("bowl"));
							this->mixerCounter++;
							}

						else 
						{
							std::cout << "You did not enter bowl\n";
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
			
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				bag->displayItem();
				std::cout << "Now you need the ginger: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
				std::cout << "Your choice: ";	
				std::cin >> choice;
				//std::cout << "\n ginger state " << bag->getItemList().at(choice-1)->getItemState() << std::endl;
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
						if (bag->getItemList().at(choice-1)->getItemName() == "ginger" && bag->getItemList().at(choice-1)->getItemState())
						{
							
							countertop.addItem(bag->removeItem("ginger"));
							std::cout << "The ginger has been removed from the bag!!\n";	
							this->mixerCounter++;							
							}	
						else 
						{
							std::cout << "Either you did not enter ginger or it has not been cut\n";
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

		
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				bag->displayItem();
				std::cout << "Now you need the chicken wings: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "chicken wings" )
						{
							
							countertop.addItem(bag->removeItem("chicken wings"));
							std::cout << "The chicken has been removed from the bag!!\n";	
							this->mixerCounter++;							
							}	
						else 
						{
							std::cout << "You did not enter chicken wings\n";
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

			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				bag->displayItem();
				std::cout << "Now you need the salt: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "salt" )
						{
							
							countertop.addItem(bag->removeItem("salt"));
							std::cout << "The salt has been removed from the bag!!\n";	
							this->mixerCounter++;							
							}	
						else 
						{
							std::cout << "You did not enter salt\n";
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
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				bag->displayItem();
				std::cout << "Now you need the pepper: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "pepper" )
						{
							
							countertop.addItem(bag->removeItem("pepper"));
							std::cout << "The pepper has been removed from the bag!!\n";	
							this->mixerCounter++;							
							}	
						else 
						{
							std::cout << "You did not enter pepper\n";
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
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				bag->displayItem();
				std::cout << "Now you need the soy sauce: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
						if (bag->getItemList().at(choice-1)->getItemName() == "soy sauce" )
						{
							
							countertop.addItem(bag->removeItem("soy sauce"));
							std::cout << "The soy sauce has been removed from the bag!!\n";	
							this->mixerCounter++;							
							}	
						else 
						{
							std::cout << "You did not enter soy sauce\n";
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
				}// end while (!valid)	
			if (this->mixerCounter == 6)
			{
				countertop.setContainerState(true); // ready to cook
				std::cout << "\nAll items have been mixed and ready to cook\n";
				}
			} // end if choice 2
		else if (choice == 3)
		{
			valid = false;
			while(! valid)
			{ // repeat as long as the input is not valid
				std::cout << "\nYou will need a deep fryer.\n";
				bag->displayItem();
				std::cout << "Please enter the deep fryer: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
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
								
						if (bag->getItemList().at(choice-1)->getItemName() == "deep fryer")
						{
							std::cout << "Now you need the oil, please enter it: (1 - " << bag->getNumItem() << ")  (or 0 if you do not want to add an item)\n";		
							std::cout << "Your choice: ";	
							std::cin >> choice;
							if (bag->getItemList().at(choice-1)->getItemName() == "oil" && countertop.getContainerState() )
							{
								bag->removeItem("deep fryer");
								countertop.addItem(deepFryer);
								countertop.addItem(bag->removeItem("oil"));
								std::cout << "\nThe chicken has been cooked and added to bag\nNow you need to go to the dining room to serve it\n";
								bag->addItem(cookedChicken);
								}
							else
							{
								std::cout << "\nEither you did not enter oil or item has not been mixed\n";
								}
							}

						else 
						{
							std::cout << "\nYou did not enter deep fryer\n";
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
			} // end if choice 3
		 }// end while isvalid
	//delete itemToThrow;
	}

/*********************************************************************
Kitchen::changeRoom
change Room function for common area : allows to move to diff rooms
*********************************************************************/
Room* Kitchen::changeRoom()
{
	valid = false;
    while(! valid)
    { // repeat as long as the input is not valid
        std::cout << "\nWhich room do you want to go to?\n";
		std::cout << "1. Go to dining room\n";
		std::cout << "2. Go to living room\n";
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
    	  		std::cout << "Enter a number between 1 and 5\n\n";
    	  		}
        	}
        if (choice == 1)
		{
			return this->back;
			} // end if choice 1
		else if (choice == 2)
		{
			return this->left;
			} // end if choice 1
		} // end while !valid
	} // end void explore

/*********************************************************************
Kitchen::~Kitchen
a default destructor for Common Area that initializes the Room pointer to 
according to the configurations
*********************************************************************/

Kitchen::~Kitchen() 
{	
	delete knife;
	delete cuttingBoard;
	delete deepFryer;
	delete bowl;
	delete cookedChicken;
	}
