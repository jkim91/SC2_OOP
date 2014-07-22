#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

#include <string>
#include "Ability.h"

using namespace std;

class GameObject;
class Combat;

class Weapon{
public:
	~Weapon();

	virtual void attack(GameObject *g) = 0;
	virtual void attackAnimation() = 0;

	//getters
	string getName();
	int getDamage();
	int getRange();
	float getCooldown();
	int getTargetType();
	Combat *getOwner();

	//setters
	void setName(string &name);
	void setDamage(int &damage);
	void setRange(int &range);
	void setCooldown(float &cooldown);
	void setTargetType(int &targetType);
	void setOwner(Combat &owner);

protected:
	string *name; //name of weapon (UNIQUE)
	int *damage; //damage of weapon (UNIQUE)
	int *range; //range of weapon (UNIQUE)
	float *cooldown; //cooldown of weapon (UNIQUE)
	const int *targetType; //target type of weapon (UNIQUE)
	Combat *owner; //combat object that owns (UNIQUE)
};

#endif