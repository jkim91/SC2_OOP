#pragma once
#ifndef _FUSION_CUTTER_H
#define _FUSION_CUTTER_H

#include "Weapon.h"

class Combat;

class FusionCutter : public Weapon{
private:
	static string NAME;
	static int DAMAGE;
	static int RANGE;
	static float COOLDOWN;
public:
	FusionCutter();
	~FusionCutter();
	
	void attack(GameObject *g);
	void attackAnimation();

};

#endif