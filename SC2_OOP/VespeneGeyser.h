#pragma once
#ifndef _VESPENE_GEYSER_H
#define _VESPENE_GEYSER_H

#include "Geyser.h"

class GasCollector;

class VespeneGeyser : public Geyser{
public:
	VespeneGeyser(); //default constructor
	VespeneGeyser(VespeneGeyser &g); //copy constructor
	virtual ~VespeneGeyser(); //destructor

	//methods
	virtual void giveResource(Worker &w);
	virtual Resource* createResource(int amount);

protected:
	static string NAME;
};

string VespeneGeyser::NAME = "Vespene Geyser";

#endif