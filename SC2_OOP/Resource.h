#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H

#include "GameObject.h"

class Worker;
class Meter;

class Resource : public GameObject
{
protected:
	Meter *amount;
	string *type;
public:
	
	int getMax(); //getter for max
	
	void setMax(int &res); //setter for max

	int getCurrent(); //getter for current
	virtual void subtract() = 0; //subtract from the current amount, differs for type of resource
	
	virtual void give(Worker &w) = 0; //give a resource fragment to a worker

	static const int STANDARD = 2500;
	static const string MINERAL;
	static const string GAS;
};

#endif