#pragma once
#ifndef _UNIT_H
#define _UNIT_H

#include "GameObject.h"

class Unit : public GameObject
{
protected:
	float *speed; //maximum speed of unit (SHARED)
	float *accel; //acceleration of unit (SHARED)
public:
	Unit();
	~Unit();

	float getSpeed(); //getter for speed
	void setSpeed(float *speed); //set the maximum speed
	void setSpeedPercent(float percent); //set the maximum speed by percentage of original

	float getAccel(); //getter for acceleration
	void setAccel(float *accel); //set the acceleration
	void setAccelPercent(float percent); //set the acceleration by percentage of original

	//stuff for movement. A moving gameobject is defined as a unit
	void move(float position[3]); //move to a position
	void move(GameObject *g); //move to an object
	void patrol(float position[3]); //patrol from current to destination
	void hold(); //hold
};

#endif