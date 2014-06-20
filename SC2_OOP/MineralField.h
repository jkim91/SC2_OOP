#pragma once
#ifndef _MINERAL_FIELD_H
#define _MINERAL_FIELD_H

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