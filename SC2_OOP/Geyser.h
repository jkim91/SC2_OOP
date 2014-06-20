#pragma once
#ifndef _GEYSER_H
#define _GEYSER_H

#include "ResourceStructure.h"

class GasCollector;

class Geyser : public ResourceStructure{
public:
	Geyser(); //default constructor
	Geyser(Geyser &g); //copy constructor
	virtual ~Geyser(); //destructor

	//abstract methods
	virtual void giveResource(Worker &w) = 0;
	virtual Resource* createResource(int amount) = 0;

	//getters
	GasCollector getGasCollector();

	//setters
	void setGasCollector(GasCollector &g);

protected:
	GasCollector *collector; //VespeneGeyser collector object on top of VespeneGeyser object

};

#endif