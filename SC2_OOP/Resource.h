#pragma once
#ifndef _RESOURCE_H
#define _RESOURCE_H

/*
	Explanation: Resource objects originate from ResourceStructures and are carried by Workers and dropped off at ResourceCenters. Resource has an amount and a type.
*/

#include <string>
#include <set>

using namespace std;

class Resource{
public:
	Resource();
	Resource(int amount, string &type);
	Resource(Resource &r);
	virtual ~Resource();

	//functions
	string getTypeValue();

	//getters
	int getAmount();
	string* getType();

	//setters
	void setAmount(int amount);
	void setType(string &type);

protected:
	//state
	int amount; //amount of resource (UNIQUE)
	string *type; //type of resource (SHARED)

};

#endif