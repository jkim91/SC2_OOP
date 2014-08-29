#pragma once
#ifndef _REGEN_METER_H
#define _REGEN_METER_H

/*
Explanation: Shield is a subclass of Health with a Regen object and cooldown
*/

#include "Meter.h"
class Regen;

class RegenMeter : public Meter{
public:
	RegenMeter(); //default constructor, use only for testing
	RegenMeter(RegenMeter &s); //copy constructor (deep-copy)
	virtual ~RegenMeter(); //destructor

	//methods
	void resetCoolDown(); //reset the cooldown

	//getters
	Regen* getRegen();

	//setters
	void setRegen(Regen &r);
	void setRegen(Regen *r);

protected:
	void restore(); //restore the shield
	
	//state
	Regen *regen;  //regen for shield meter (SHARED)
	bool reset; //reset cooldown flag
};

#endif