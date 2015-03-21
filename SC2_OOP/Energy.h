#pragma once
#ifndef _ENERGY_H
#define _ENERGY_H

#include "Meter.h"

class Regen;
class GameObject;

using namespace std;

class Energy : public Meter{
public:
	Energy();
	Energy(Energy &e);
	Energy(float &max, GameObject *g, float &rate, float &cooldown);
	virtual ~Energy();

	Regen* getRegen();
	GameObject* getOwner();

	void setRegen(Regen* r);
	void setOwner(GameObject *owner);

protected:
	Regen *r;
	GameObject *owner;
};

#endif