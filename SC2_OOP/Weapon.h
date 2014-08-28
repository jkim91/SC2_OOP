#pragma once
#ifndef _WEAPON_H
#define _WEAPON_H

class GameObject;

#include <string>
#include <set>

using namespace std;

class Weapon{
public:
	Weapon();
	~Weapon();

	//functions
	virtual void attack(GameObject* g);
	string getNameValue();
	int getLevelValue();
	float getDamageValue();
	float getModifierValue();
	float getRangeValue();
	float getCooldownValue();

	//getters
	string* getName();
	int* getLevel();
	float* getDamage();
	float* getModifier();
	float* getRange();
	float* getCooldown();
	set<string> getWeaponNames();

	//setters
	void setName(string &name);
	void setLevel(int level);
	void setDamage(float damage);
	void setModifier(float &modifier);
	void setRange(float &range);
	void setCooldown(float &cooldown);
	void setWeaponNames(set<string> names);

protected:
	//state
	string* name; //name of weapon (SHARED)
	int* level; //level of weapon, defaults to zero (SHARED)
	float* damage; //damage of weapon (SHARED)
	float* modifier; //damage modifier of weapon via upgrade (SHARED)
	float* range; //range of weapon (SHARED)
	float* cooldown; //cooldown of weapon (SHARED)
	static set<string> weaponNames; //list of strings of possible weapons names (UNIQUE)	
};

#endif