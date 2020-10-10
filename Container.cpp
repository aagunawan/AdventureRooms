/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Container Class Implementation
*********************************************************************/

#include "Container.h"

/*********************************************************************
Container::Container
a constructor for Container initializing the  name and max weight
*********************************************************************/
Container::Container()
{
	this->containerName = "";
	this->maxWeight = 0;
	this->numItems = 0;
	this->weight = 0;
	this->containerState = false;
	}
	
/*********************************************************************
Container::setContainerName

*********************************************************************/
void Container::setContainerName(std::string containerName)
{
	this->containerName = containerName;
	}

/*********************************************************************
Container::setMaxWeight

*********************************************************************/
void Container::setMaxWeight(int maxWeight)
{
	this->maxWeight = maxWeight;
	}

/*********************************************************************
Container::setBagWeight

*********************************************************************/
void Container::setWeight(int addedWeight)
{
	this->weight += addedWeight;
	}

/*********************************************************************
Container::getBagWeight

*********************************************************************/
int Container::getWeight()
{
	return this->weight;
	}
	
/*********************************************************************
Container::getContainerName

*********************************************************************/
std::string Container::getContainerName()
{
	return this->containerName;
	}

/*********************************************************************
Container::getItemName

*********************************************************************/
int Container::getMaxWeight()
{
	return this->maxWeight;
	}

/*********************************************************************
Container::addItem

*********************************************************************/
void Container::addItem(Item* itemToAdd)
{
	if ((this->maxWeight - this->weight) >=  itemToAdd->getItemWeight())
	{
		
		container.push_back(itemToAdd);
		setWeight(itemToAdd->getItemWeight());
		this->numItems++;
		}
	else
	{
		std::cout << "The item is too heavy for the " << getContainerName() << std::endl;
		}
	}

/*********************************************************************
Container::displayItem

*********************************************************************/
void Container::displayItem()
{	
	std::cout << "\nItems in "<< this->containerName <<" :" << std::endl;
	if (container.size() != 0)
	{
		for (index = 0; index < container.size(); index++)
		{
			std::cout << (index+1) << ". " << container.at(index)->getItemName() << std::endl;
			}
		}
	else
	{
		std::cout << "It is empty\n";
		}	
	std::cout << "Current weight of "<< this->containerName <<" : " << getWeight() << " lbs" <<std::endl;
	}

/*********************************************************************
Container::getNumItem

*********************************************************************/
int Container::getNumItem()
{	
	return this->numItems;
	}

/*********************************************************************
Container::getItemList

*********************************************************************/
std::vector<Item*> Container::getItemList()
{	
	return this->container;
	}
	
/*********************************************************************
Container::removeItem

*********************************************************************/
Item* Container::removeItem(std::string itemName)
{	
	Item* removedItem;
	for (index = 0; index < container.size(); index++)
	{
		if (container.at(index)->getItemName() == itemName)
		{	
			removedItem = container.at(index);
			container.erase(container.begin()+index);
			setWeight(-1*removedItem->getItemWeight());	
			this->numItems--;	
			} // end container.at ...
		} // end for index = 0	
	return removedItem;
	}

/*********************************************************************
Container::getContainerState

*********************************************************************/
bool Container::getContainerState()
{
	return this->containerState;
	}

/*********************************************************************
Item::setContainerState

*********************************************************************/
void Container::setContainerState(bool state)
{
	this->containerState = state;
	}