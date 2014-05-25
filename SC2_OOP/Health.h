#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

class Meter;

/*
Explanation:
	health has two pointers to objects: a Meter object for a gauge and an Armor object for the damage offset. Every health object has a unique meter for its own health. Health objects can reference the same Armor object. So armor MUST be created/deleted by a third-party.

*/

class Health : public Meter
{
public:
	Health();
	Health(int &max); //primitive constructor, create new meter, shallow-copy armor
	Health(Health &h); //copy constructor, deep-copy meter, shallow-copy armor

	virtual void regen(); //regenerate health, default does nothing, so subclass for function
};

#endif