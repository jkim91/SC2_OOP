#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

#include <string>
#include "Ability.h"

using namespace std;

class GameObject;
class Combat;

class Weapon{
protected:
	string *name; //name of weapon (UNIQUE)
	int *damage; //damage of weapon (UNIQUE)
	int *range; //range of weapon (UNIQUE)
	float *cooldown; //cooldown of weapon (UNIQUE)
	const int *targetType; //target type of weapon (UNIQUE)
	Combat *owner; //combat object that owns (UNIQUE)
public:
	~Weapon();

	virtual void attack(GameObject *g) = 0;
	virtual void attackAnimation() = 0;

	string getName();
	void setName(string &name);

	int getDamage();
	void setDamage(int &damage);
	
	int getRange();
	void setRange(int &range);

	float getCooldown();
	void setCooldown(float &cooldown);

	int getTargetType();
	void setTargetType(int &targetType);

	Combat *getOwner();
	void setOwner(Combat &owner);
};

#endif