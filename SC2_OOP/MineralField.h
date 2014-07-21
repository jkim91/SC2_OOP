#pragma once
#ifndef _MINERAL_FIELD_H
#define _MINERAL_FIELD_H

/*
Explanation: MineralField is a ResourceStructure that a Worker can obtain Resource from directly.
*/

#include "ResourceStructure.h"

class Worker;

class MineralField: public ResourceStructure
{
public:
	MineralField();
	MineralField(MineralField &m);
	virtual ~MineralField();
	
	//methods
	virtual void giveResource(Worker &w);
	virtual Resource* createResource(int amount);

protected:
	static string NAME; //name of mineral field
};

string MineralField::NAME = "Mineral Field";

#endif