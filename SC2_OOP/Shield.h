#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

#include "Health.h"

/*
Explanation: Shield is a subclass of Health and it actually regenerates
*/

class Shield : public Health{
protected:
public:
	Shield(); //default constructor
	Shield(int &max, Armor &a); //primitive constructor
	Shield(Meter &m, Armor &a); //primitive constructor
	Shield(Shield &s); //copy constructor
	~Shield();

	void regen();
};

#endif