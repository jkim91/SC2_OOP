#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H

/*
Explanation:
	Resouce is a gameobject that workers interact with to gather resources (e.g. minerals and vespene gas). The meter object is for the amount of resource it has left and so it is always unique.
*/

#include "GameObject.h"

class Worker;
class Meter;

class Resource : public GameObject
{
protected:
	virtual void initDetails(); //refer to GameObject

	virtual void destroyDetails(); //refer to GameObject

	Meter *amount; //amount of resource it currently has. (UNIQUE)
public:
	virtual ~Resource(); //destructor. destroys the meter, but type is not deleted.

	int getCurrentAmount(); //getter for current
	virtual void subtract() = 0; //subtract from the current amount by default
	void subtract(int request); //subtract from the current amount by requested
	
	int getMaxAmount(); //getter for max
	void setMaxAmount(int &res); //setter for max


	static const int STANDARD = 2500;
};

#endif