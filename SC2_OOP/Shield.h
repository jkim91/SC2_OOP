#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

#include "Health.h"

/*
Explanation: Shield is a subclass of Health and it regenerates
*/

class Shield : public Health{
protected:
public:
	Shield(); //default constructor
	Shield(int &max); //primitive constructor
	Shield(Shield &s); //copy constructor

	void regen();
};

#endif