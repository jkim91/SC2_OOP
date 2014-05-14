#pragma once
#ifndef _WORKER_H
#define _WORKER_H

#include <string>

using namespace std;

class Resource;
class GatherCenter;

class Worker{
public:
	virtual void gather(Resource &r); //gather from a resource and obtain a resource fragment
	virtual void dropOff(GatherCenter &g); //drop the resource fragment at a gather center
	virtual void gatherAnimation() = 0; //gather animation
	virtual void dropOffAnimation() = 0;//drop-off animation
};

#endif