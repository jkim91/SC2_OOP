#pragma once
#ifndef _WORKER_H
#define _WORKER_H

#include <string>

using namespace std;

class ResourceStructure;
class Resource;
class ResourceCenter;

class Worker{
public:
	Worker(); //default constructor
	Worker(Worker &w); //copy constructor
	virtual ~Worker(); //destructor

	virtual void gather(ResourceStructure &r); //gather from a resource and obtain a resource fragment
	virtual void dropOff(ResourceCenter *g); //drop the resource fragment at a gather center
	//virtual void gatherAnimation() = 0; //gather animation
	//virtual void dropOffAnimation() = 0;//drop-off animation
protected:
	Resource *res; //resource that the Worker object possesses
};

#endif