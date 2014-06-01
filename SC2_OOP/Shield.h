#pragma once
#ifndef _SHIELD_H
#define _SHIELD_H

/*
Explanation: Shield has a meter and a regen object
*/

class Meter;
class Regen;
class Armor;

class Shield{
protected:
	static float cooldown; //ALL shields will have the same cooldown timer
	float* currentCooldown;
	Meter* meter;
	Regen* regen;
	Armor* armor;
public:
	Shield(); //default constructor, use only for testing
	Shield(Meter &m, Regen &r, Armor &a); //primitive constructor, creates a new meter and regen object
	Shield(Shield &s); //copy constructor (deep-copy)
	~Shield(); //destructor

	Meter* getMeter();
	Armor* getArmor();
	Regen* getRegen();

};

float Shield::cooldown = 10.0;

#endif