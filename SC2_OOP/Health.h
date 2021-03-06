/*
	Explanation: A Health object represents the health of a GameObject. It is a subclass of Meter with an Armor pointer, and a GameObject pointer.
	The origin of the Armor object comes from the corresponding Player subclass, where it is created and defined. 
	The Gameobject pointer points to the GameObject that owns the Health object. The corresponding GameObject know about the Health object also.

	State, Getter, and Setters:
		-all getters and setters from superclass remains unchanged.
		-armor, and owner all have getters and setters.
	Methods and Functions:
		-subtract method re-define the implementation in Meter's. It takes Armor into account and modify the Meter accordingly.
	Constructors and Destructors:
		-default constructor, copy constructor, and destructor all follow suit with superclass.	
		-parametrized constructor takes in a float reference, Armor pointer, and GameObject pointer and set the state accordingly.
*/

#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

#include <string>
#include "Meter.h"

class Armor;
class GameObject;

using namespace std;

class Health: public Meter{
public:
	Health();
	Health(Health &h);
	Health(float &max_health, Armor* a, GameObject *g);
	virtual ~Health();

	//methods
	void subtract(float amount);

	//getters
	Armor* getArmor();
	GameObject* getOwner();

	//setters
	void setArmor(Armor *a);
	void setOwner(GameObject *g);

protected:
	Armor* armor;
	GameObject* owner;
};

#endif