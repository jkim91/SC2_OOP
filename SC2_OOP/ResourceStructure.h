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
	virtual void giveResource(Worker &w, int request); //give Resource object to Worker with specified amount
	
	//abstract methods
	virtual void giveResource(Worker &w) = 0; //give Resource object to Worker
	virtual Resource* createResource(int request) = 0; //create the appropriate resource (Factory Method)
	
	//getters
	Meter<int> getAmount(); //getter for amount meter
	int getMaxAmount(); //getter for max amount value
	int getCurrentAmount(); //getter for current amount value

	//setters
	void setAmount(Meter<int> &m); //setter for amount
	
protected:
	Meter<int> *amount; //amount of resource it currently has. (UNIQUE)
	
	static int STANDARD; //Starting amount of resource for structure
	static Meter<float> HEALTH_METER; //meter for HEALTH
	static Armor ARMOR; //Armor for all ResourceStructures. All ResourceStructures are invulnerable
	static float SIGHT; //sight radius for all resource structures
	static set<string> ATTRIBUTES; //attributes for all resource structures
};

int ResourceStructure::STANDARD = 2500;
float ResourceStructure::SIGHT = 0.0;
set<string> ResourceStructure::ATTRIBUTES = set<string>();

#endif