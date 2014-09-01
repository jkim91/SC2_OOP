#pragma once
#ifndef _RESOURCE_REFINER_H
#define _RESOURCE_REFINER_H

/*
Explanation: GasCollector is a "skin" for Geyser. GasCollector cannot exist without a Geyser. Has its own sight and armor. Armor must be implemented by subclasses.
*/


#include "GameObject.h"

class RawResourceStructure;
class Worker;

class ResourceRefiner : public GameObject{
public:
	//constructors and destructor
	ResourceRefiner(); //not to be used. GasCollector should not exist without geyser
	ResourceRefiner(RawResourceStructure &g); //only constructor to be used. Copy constructor does not make sense here.
	virtual ~ResourceRefiner(); //destructor

	//methods
	virtual void giveResource(Worker &w); //give resource from ResourceStructure to Worker

	//getters
	RawResourceStructure* getResourceStructure();

	//setters
	void setResourceStructure(RawResourceStructure &g);

protected:
	virtual void initArmor() = 0;

	RawResourceStructure *res;

	static float SIGHT;
	static float ARMOR_VALUE;
};

#endif