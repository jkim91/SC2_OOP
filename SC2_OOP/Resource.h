#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H

/*
	Explanation: Resource is the superclass of all resources, mineral and gas. They are carried by Workers and dropped off at ResourceCenters.
*/

class Resource{
public:
	Resource();
	Resource(int amount, const int &type);
	Resource(Resource &r);
	virtual ~Resource();

	//getters
	int getAmount();
	int getType();

	//setters
	void setAmount(int amount);
	void setType(const int &type);

	//constants
	static const int MINERAL = 0;
	static const int GAS = 1;

protected:
	int amount;
	const int *type;
};

#endif