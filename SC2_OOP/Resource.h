#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H

/*
	Explanation: Resource objects originate from ResourceStructures and are carried by Workers and dropped off at ResourceCenters. Resource has an amount and a type.
*/

class Resource{
public:
	Resource();
	Resource(int amount, int &type);
	Resource(Resource &r);
	virtual ~Resource();

	//getters
	int getAmount();
	int getType();

	//setters
	void setAmount(int amount);
	void setType(int &type);

protected:
	int amount; //amount of resource (UNIQUE)
	const int *type; //type of resource (SHARED)

	//constants
	static int MINERAL;
	static int GAS;
};

#endif