#pragma once
#ifndef _RESOURCE_STRUCTURE_H
#define _RESOURCE_STRUCTURE_H

/*
Explanation:
	ResouceStructure is a gameobject that workers interact with to gather resources (e.g. minerals and vespene gas). The meter object is for the amount of resource it has left and so it is always unique.
*/

#include "GameObject.h"

template <class T> class Meter;
class Resource;
class Worker;

class ResourceStructure : public GameObject
{
public:
	ResourceStructure(); //default constructor
	ResourceStructure(ResourceStructure &r); //copy constructor
	virtual ~ResourceStructure(); //destructor. destroys the meter, but type is not deleted.

	//methods
	virtual void subtract() = 0; //subtract from the current amount via default
	void subtract(int request); //subtract from the current amount by requested
	void giveResource(Worker &w); //give Resource object to Worker
	virtual Resource* createResource() = 0; //create the appropriate resource (Factory Method)
	
	//getters
	Meter<int> getAmount(); //getter for amount meter
	int getMaxAmount(); //getter for max amount value
	int getCurrentAmount(); //getter for current amount value

	//setters
	void setAmount(Meter<int> &m); //setter for amount
	
protected:
	Meter<int> *amount; //amount of resource it currently has. (UNIQUE)
	
	static int STANDARD;
};

int ResourceStructure::STANDARD = 2500;

#endif