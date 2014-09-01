#pragma once
#ifndef _VESPENE_GEYSER_H
#define _VESPENE_GEYSER_H

#include "RawResourceStructure.h"

class GasCollector;

class VespeneGeyser : public RawResourceStructure{
public:
	VespeneGeyser(); //default constructor
	VespeneGeyser(VespeneGeyser &g); //copy constructor
	virtual ~VespeneGeyser(); //destructor

	//methods
	virtual void giveResource(Worker &w);
	virtual Resource* createResource(int amount);

protected:
	static string NAME; //String form of Vespene Geyser
	static string TYPE; //type of Resource to give to Worker
};

#endif