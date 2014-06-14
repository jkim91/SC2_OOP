#pragma once
#ifndef _MINERAL_FIELD_H
#define _MINERAL_FIELD_H

#include "ResourceStructure.h"

class MineralField: public ResourceStructure
{
public:
	MineralField();
	MineralField(MineralField &m);
	virtual ~MineralField();

	//methods
	void subtract();
};

#endif