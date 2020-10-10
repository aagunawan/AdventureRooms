/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Item Class Implementation
*********************************************************************/

#include "Item.h"

/*********************************************************************
Item::Item
a constructor for item initializing the item name and weight
*********************************************************************/
Item::Item()
{
	this->itemName = "";
	this->itemWeight = 0;
	this->itemState = false;
	}
/*********************************************************************
Item::setItemName

*********************************************************************/
void Item::setItemName(std::string itemName)
{
	this->itemName = itemName;
	}

/*********************************************************************
Item::setItemWeight

*********************************************************************/
void Item::setItemWeight(int itemWeight)
{
	this->itemWeight = itemWeight;
	}
	
/*********************************************************************
Item::getItemName

*********************************************************************/
std::string Item::getItemName()
{
	return this->itemName;
	}

/*********************************************************************
Item::getItemName

*********************************************************************/
int Item::getItemWeight()
{
	return this->itemWeight;
	}

/*********************************************************************
Item::getItemState

*********************************************************************/
bool Item::getItemState()
{
	return this->itemState;
	}

/*********************************************************************
Item::setItemState

*********************************************************************/
void Item::setItemState(bool state)
{
	this->itemState = state;
	}