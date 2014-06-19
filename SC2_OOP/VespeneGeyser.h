#pragma once
#ifndef _VESPENE_GEYSER_H
#define _VESPENE_GEYSER_H

#include "ResourceStructure.h"

class GasCollector;

class VespeneGeyser : public ResourceStructure{
public:
	VespeneGeyser(); //default constructor
	VespeneGeyser(VespeneGeyser &g); //copy constructor
	virtual ~VespeneGeyser(); //destructor

	//methods
	virtual void giveResource(Worker &w);
	virtual Resource* createResource(int amount);

	//getters
	GasCollector getGasCollector();

	//setters
	void setGasCollector(GasCollector &g);

protected:
	GasCollector *collector; //VespeneGeyser collector object on top of VespeneGeyser object
};

#endif