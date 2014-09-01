#pragma once
#ifndef _RAW_RESOURCE_STRUCTURE_H
#define _RAW_RESOURCE_STRUCTURE_H

/*
Explanation: Geyser is a ResourceStructure that REQUIRES a GasCollector for a Worker to obtain Resource.
*/

#include "ResourceStructure.h"

class ResourceRefiner;

class RawResourceStructure : public ResourceStructure{
public:
	RawResourceStructure(); //default constructor
	RawResourceStructure(RawResourceStructure &g); //copy constructor
	virtual ~RawResourceStructure(); //destructor

	//abstract methods
	virtual void giveResource(Worker &w) = 0;
	virtual Resource* createResource(int amount) = 0;

	//getters
	ResourceRefiner* getRefiner();

	//setters
	void setRefiner(ResourceRefiner *g);

protected:
	ResourceRefiner* refiner; //VespeneGeyser collector object on top of VespeneGeyser object

};

#endif