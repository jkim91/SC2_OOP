#pragma once
#ifndef _WORKER_H
#define _WORKER_H

#include "Unit.h"

class ResourceStructure;
class Resource;
class ResourceCenter;

class Worker : public Unit{
public:
	Worker(); //default constructor
	Worker(Worker &w); //copy constructor
	virtual ~Worker(); //destructor

	virtual void gather(ResourceStructure &r); //gather from a resource and obtain a resource fragment
	virtual void returnCargo(); //return cargo to nearest ResourceCenter, if possible
	virtual void dropOff(ResourceCenter &g); //drop the resource fragment at a gather center

protected:
	Resource *res; //resource that the Worker object possesses
};

#endif