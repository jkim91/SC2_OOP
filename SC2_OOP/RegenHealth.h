/*
	Explanation: A Health object represents the health of a GameObject. It is a subclass of Meter with an Armor pointer, and a GameObject pointer.
	The origin of the Armor object comes from the corresponding Player subclass, where it is created and defined. 
	The Gameobject pointer points to the GameObject that owns the Health object. The corresponding GameObject know about the Health object also.

	State, Getter, and Setters:
		-meter, armor, and owner all have getters and setters.
	Methods and Functions:
		-subtract method re-define the implementation in Meter's. It takes Armor into account and modify the Meter accordingly.
	Constructors and Destructors:
		-default constructor, copy constructor, and destructor all follow suit with superclass.	
		-parametrized constructor takes in a float reference, Armor pointer, and GameObject pointer and set the state accordingly.
*/

#pragma once
#ifndef _REGEN_HEALTH_H
#define _REGEN_HEALTH_H

#include <string>
#include "Health.h"

using namespace std;

class RegenHealth : public Health{
public:
	RegenHealth();
	RegenHealth(RegenHealth &h);
	RegenHealth(float &max_health, Armor* a, GameObject* g, float &rate);

	virtual void execute();

	float* getRate();
	float getRateValue();
	float* getCooldown();
	float getCooldownValue();

	void setRate(float &f);
	void setCooldown(float &f);

protected:
	float* rate;
	float* cooldown;
};

#endif