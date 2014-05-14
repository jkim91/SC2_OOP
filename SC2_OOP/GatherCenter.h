#pragma once
#ifndef _GATHER_CENTER_H
#define _GATHER_CENTER_H

#include <string>

using namespace std;

class GatherCenter{
public:
	virtual void allocate(pair<string, int> &resource);
};

#endif