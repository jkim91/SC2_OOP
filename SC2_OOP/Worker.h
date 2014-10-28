#pragma once
#ifndef _WORKER_H
#define _WORKER_H

#include "Unit.h"

class ResourceStructure;
class Resource;
class ResourceCenter;

class Worker: public Unit{
public:
	Worker(); //default constructor
	Worker(Worker &w); //copy constructor
	virtual ~Worker(); //destructor

	//methods
	virtual void gather(ResourceStructure *r); //gather from a resource and obtain a resource fragment
	virtual void dropOff(ResourceCenter *c); //drop the resource fragment at a gather center

	//abstract methods
	virtual void returnCargo() = 0; //return cargo to nearest ResourceCenter, if possible

	//getter
	Resource* getResource();

	//setter
	void setResource(Resource *res);

protected:
	Resource *res; //resource that the Worker object possesses
};

#endif