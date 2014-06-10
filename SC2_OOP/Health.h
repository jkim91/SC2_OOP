#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

/*
	Explanation: Health is an object for all GameObjects. It has a meter for its health and armor, which affects how health is changed by damage.

*/

class Meter;
class Armor;

class Health{
public:
	Health(); //default constructor
	Health(Meter &m, Armor &a); //primitive constructor
	Health(Health &h); //copy constructor
	virtual ~Health();

	//getters
	Meter* getMeter();
	Armor* getArmor();

	//setters
	void setMeter(Meter &m);
	void setArmor(Armor &a);

	void add(float amount);
	void subtract(float amount);
protected:
	Meter* meter; //health meter (UNIQUE)
	Armor* armor; //armor (SHARED)
	static Armor DEFAULT_ARMOR; //armor for default constructor
};

#endif