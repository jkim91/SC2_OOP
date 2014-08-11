#pragma once
#ifndef _COMBAT_H
#define _COMBAT_H

class GameObject;
class Weapon;

class Combat{
public:
	Combat();
	Combat(Combat &c);
	~Combat();

	//functions
	virtual void attack(GameObject *g);

	//getters
	Weapon* getWeapon();

	//setters
	void setWeapon(Weapon &w);

protected:
	Weapon* weapon; //weapon for a Combat object (SHARED)
};

#endif