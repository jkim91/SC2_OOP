#pragma once
#ifndef _GAS_COLLECTOR_H
#define _GAS_COLLECTOR_H

#include "GameObject.h"

class Gas;

class GasCollector : public GameObject{
public:
	GasCollector(); //default constructor
	GasCollector(GasCollector &g); //copy constructor
	virtual ~GasCollector(); //destructor

	//methods
	void subtract();

	//getters
	Gas* getGas();

	//setters
	void setGas(Gas &g);

protected:
	Gas *geyser;
};

#endif