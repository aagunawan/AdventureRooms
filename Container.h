/*********************************************************************
** Author: Aloysius Gunawan
** Date: 03/11/2017
** Description: Final Project CS162 - AAG
This program contains Container Class Prototype
*********************************************************************/

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <string>
#include "Item.h"
#include <vector>

class Container
{
protected:
	std::string containerName; // name of items
	int maxWeight; // in lbs
	std::vector<Item*> container;
	int numItems; // number of items in container
	int index;
	int weight;
	bool containerState;
	
public:
	Container();
	void setContainerName(std::string);
	void setMaxWeight(int);
	std::string getContainerName();	
	int getMaxWeight();
	void displayItem();
	void addItem(Item*);
	//void removeItem(std::string);
	Item* removeItem(std::string);
	int getNumItem();
	std::vector<Item*> getItemList();
	void setWeight(int);
	int getWeight();
	void setContainerState(bool);
	bool getContainerState();
	};

#endif