#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

class Armor;
class Meter;

/*
Explanation:
	health has two pointers to objects: a Meter object for a gauge and an Armor object for the damage offset. Every health object has a unique meter for its own health. Health objects can reference the same Armor object. So armor MUST be created/deleted by a third-party.

*/

class Health
{
protected:
	Meter *meter; //health meter (UNIQUE)
	Armor *armor; //armor associated with health (SHARED)
public:
	Health(); //default constructor
	Health(int max, Armor &armor); //primitive constructor, create new meter, shallow-copy armor
	Health(Meter &m, Armor &a); //primitive constructor, same impl. as last one
	Health(Health &h); //copy constructor, deep-copy meter, shallow-copy armor
	~Health();

	int getCurrent(); //getter for current
	void addHealth(int amount); //add to health
	void subHealth(int amount); //subtract from health
	int getMax(); //getter for max
	void resetHealthToMax(); //reset current to max

	Meter *getMeter(); //getter for meter
	void setMeter(Meter &m); //setter for health meter, deep copy

	Armor *getArmor(); //getter for armor
	void setArmor(Armor &a); //setter for armor, shallow copy

	virtual void regen(); //regenerate health
};

#endif