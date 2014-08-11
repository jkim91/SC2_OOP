#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

#include <string>

using namespace std;

class Weapon{
public:
	Weapon();
	~Weapon();

	//functions
	string getNameValue();
	float getDamageValue(); //get damage value
	float getModifierValue(); //get modifier value
	float getRangeValue();
	float getCooldownValue();

	//getters
	string* getName();
	float* getDamage();
	float* getModifier();
	float* getRange();
	float* getCooldown();

	//setters
	void setName(string &name);
	void setDamage(float &damage);
	void setModifier(float &modifier);
	void setRange(float &range);
	void setCooldown(float &cooldown);

protected:
	string *name; //name of weapon (SHARED)
	float *damage; //damage of weapon (SHARED)
	float *modifier; //damage modifier of weapon via upgrade (SHARED)
	float *range; //range of weapon (SHARED)
	float *cooldown; //cooldown of weapon (SHARED)
};

#endif