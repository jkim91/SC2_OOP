#pragma once
#ifndef _UNIT_H
#define _UNIT_H

#include "GameObject.h"

class Kinematics_2D;

class Unit : public GameObject
{
public:
	Unit();
	Unit(Unit &u);
	virtual ~Unit();
	
	//methods
	virtual bool stop(); //stop the unit immediately
	virtual bool move(float position[3]); //move to a position
	virtual bool patrol(float position[3]); //patrol from current to destination
	virtual bool hold(); //hold

	//value getter
	int getSupplyValue();

	//getter
	int* getSupply();
	Kinematics_2D* getMovement() const;
	
	//setter
	void setSupply(int* supply);
	void setMovement(Kinematics_2D &k);

protected:
	int* supply; //supply required for unit (SHARED)
	Kinematics_2D* movement; //Kinematics object for the unit to move (UNIQUE)
};

#endif