/*
	Explanation: A Health object represents the health of a GameObject. It consisted of a Meter pointer, an Armor pointer, and a GameObject pointer.
	The origin of the Armor object comes from the corresponding Player subclass, where it is created and defined. 
	The Meter object is unique to EVERY Health object. Hence, the Meter object is deleted by the Health class destructor and every method that creates a Meter creates a deep copy of a Meter object.
	The Gameobject pointer points to the GameObject that owns the Health object. The corresponding GameObject know about the Health object also.

	State, Getter, and Setters:
		-meter, armor, and owner all have getters and setters.
	Methods and Functions:
		-subtract method re-define the implementation in Meter's. It takes Armor into account and modify the Meter accordingly.
	
*/

#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

#include <string>

class Armor;
class Meter;
class GameObject;

using namespace std;

class Health{
public:
	Health();
	Health(float &max_health, Armor* a);
	Health(Health &h);
	virtual ~Health();

	//methods
	void subtract(float amount);

	//getters
	Armor* getArmor();
	Meter* getMeter();
	GameObject* getOwner();

	//setters
	void setArmor(Armor &a);
	void setMeter(Meter &m);

protected:
	Armor* armor;
	Meter* meter;
	GameObject* owner;
};

#endif