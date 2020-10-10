/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Item Class Prototype
*********************************************************************/

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item
{
protected:
	std::string itemName; // name of items
	int itemWeight; // in lbs
	bool itemState;
	
public:
	Item();
	void setItemName(std::string);
	void setItemWeight(int);
	std::string getItemName();	
	int getItemWeight();
	void setItemState(bool);
	bool getItemState();
	};

#endif