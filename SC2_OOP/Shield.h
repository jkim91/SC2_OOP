#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

#include "Meter.h"

/*
Explanation: Shield is a subclass of Meter and it regenerates
*/

class Shield : public Meter{
protected:
	static const float cooldown; //ALL shields will have the same cooldown timer
	float* currentCooldown;
	void regen();
public:
	Shield(); //default constructor
	Shield(float &max); //primitive constructor
	Shield(Shield &s); //copy constructor
	~Shield(); //destructor

};

const float Shield::cooldown = 10.0;

#endif