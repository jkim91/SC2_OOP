#pragma once
#ifndef _MINERAL_H
#define _MINERAL_H

#include "Resource.h"

class Mineral: public Resource
{
protected:
public:
	Mineral();
	void subtract();
};

#endif