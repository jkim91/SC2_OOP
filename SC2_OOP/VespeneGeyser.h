#pragma once
#ifndef _VESPENE_GEYSER_H
#define _VESPENE_GEYSER_H

#include "ResourceStructure.h"

class VespeneGeyserCollector;

class VespeneGeyser : public ResourceStructure{
public:
	VespeneGeyser(); //default constructor
	VespeneGeyser(VespeneGeyser &g); //copy constructor
	virtual ~VespeneGeyser(); //destructor

	//methods
	void subtract();

	//getters
	VespeneGeyserCollector* getVespeneGeyserCollector();

	//setters
	void setVespeneGeyserCollector(VespeneGeyserCollector &g);

protected:
	VespeneGeyserCollector *collector; //VespeneGeyser collector object on top of VespeneGeyser geyser
};

#endif