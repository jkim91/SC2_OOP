#pragma once
#ifndef _GAS_COLLECTOR_H
#define _GAS_COLLECTOR_H

/*
Explanation: GasCollector is a "skin" for Geyser. GasCollector cannot exist without a Geyser. Has its own sight and armor.
*/


#include "GameObject.h"

class Geyser;
class Worker;

class GasCollector : public GameObject{
public:
	//constructors and destructor
	GasCollector(); //not to be used. GasCollector should not exist without geyser
	GasCollector(Geyser &g);
	GasCollector(GasCollector &g);
	virtual ~GasCollector();

	//methods
	virtual void giveResource(Worker &w); //give resource from ResourceStructure to Worker

	//getters
	Geyser* getGeyser();

	//setters
	void setGeyser(Geyser &g);

protected:
	Geyser *geyser;

	static float SIGHT;
	static Armor ARMOR;
};

#endif