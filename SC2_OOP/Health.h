#pragma once
#ifndef _HEALTH_H
#define _HEALTH_H

/*
	Explanation: Health is an object for all GameObjects. It has a meter for its health and armor, which affects how health is changed by damage.
*/

template <class T> class Meter;
class Armor;

class Health{
public:
	Health(); //default constructor
	Health(Meter<float> &m, Armor &a); //primitive constructor
	Health(Health &h); //copy constructor
	virtual ~Health();

	//methods
	void add(float amount); //add amount to health meter
	void subtract(float amount); //subtract amount from health meter

	//getters
	Meter<float> getMeter();
	Armor getArmor();

	//accessors
	Meter<float>* accessMeter();
	Armor* accessArmor();

	//setters
	void setMeter(Meter<float> &m);
	void setMeter(Meter<float> *m);
	void setArmor(Armor &a);
	void setArmor(Armor *a);

protected:
	Meter<float> *meter; //health meter (UNIQUE)
	Armor* armor; //armor (SHARED)
	static Armor DEFAULT_ARMOR; //armor for default constructor
};

#endif