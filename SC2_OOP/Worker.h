#pragma once
#ifndef _WORKER_H
#define _WORKER_H

class ResourceStructure;
class Resource;
class ResourceCenter;

class Worker{
public:
	Worker(); //default constructor
	Worker(Worker &w); //copy constructor
	virtual ~Worker(); //destructor

	//methods
	virtual void gather(ResourceStructure &r); //gather from a resource and obtain a resource fragment
	
	//abstract methods
	virtual void returnCargo() = 0; //return cargo to nearest ResourceCenter, if possible
	virtual void dropOff(ResourceCenter &g) = 0; //drop the resource fragment at a gather center

	//getter
	Resource* getResource() const;

	//setter
	void setResource(Resource *res);

protected:
	Resource *res; //resource that the Worker object possesses
};

#endif