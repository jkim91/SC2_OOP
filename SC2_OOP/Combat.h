#pragma once
#ifndef _COMBAT_H
#define _COMBAT_H

class GameObject;
class Weapon;

class Combat{
public:
	virtual void attack(GameObject *g) = 0;
};

#endif