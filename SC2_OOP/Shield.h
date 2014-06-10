#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

/*
Explanation: Shield is a subclass of Health with a Regen object and cooldown
*/

#include "Health.h"
class Regen;

class Shield : public Health{
public:
	Shield(); //default constructor, use only for testing
	Shield(Meter &m, Armor &a, Regen &r); //primitive constructor, creates a new meter and regen object
	Shield(Shield &s); //copy constructor (deep-copy)
	~Shield(); //destructor

	Regen* getRegen();
	void setRegen(Regen &r);
protected:
	Meter* coolDown; //cooldown for regen (UNIQUE)
	Regen* regen; 
	static float COOLDOWN_LIMIT;
};

float Shield::COOLDOWN_LIMIT = 10.0;

#endif