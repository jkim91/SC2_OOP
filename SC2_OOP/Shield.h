#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

/*
Explanation: Shield is a subclass of Health with a Regen object and cooldown
*/

#include "Health.h"

template <class T> class Regen;
template <class T> class Meter;

class Shield : public Health{
public:
	Shield(); //default constructor, use only for testing
	Shield(Meter<float> &m, Armor &a, Regen<float> &r); //primitive constructor, creates a new meter and regen object
	Shield(Shield &s); //copy constructor (deep-copy)
	virtual ~Shield(); //destructor

	//methods
	void resetCoolDown(); //reset the cooldown

	//getters
	Regen<float> getRegen();
	Meter<float> getCoolDown();

	//setters
	void setRegen(Regen<float> &r);
	void setRegen(Regen<float> *r);
	void setCoolDown(Meter<float> &m);
	void setCoolDown(Meter<float> *m);

protected:
	void restore(); //restore the shield

	Meter<float> *coolDown; //cooldown for regen (UNIQUE)
	Regen<float> *regen;  //regen for shield meter (SHARED)
	bool reset; //reset cooldown flag

	static float COOLDOWN_LIMIT; //default cooldown max
};

float Shield::COOLDOWN_LIMIT = 10.0;

#endif