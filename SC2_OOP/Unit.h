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
	void stop(); //stop the unit immediately
	void move(float position[3]); //move to a position
	void patrol(float position[3]); //patrol from current to destination
	void hold(); //hold

	//getter
	Kinematics_2D* getMovement() const;

	//setter
	void setMovement(Kinematics_2D &k);

protected:
	Kinematics_2D *movement;
};

#endif