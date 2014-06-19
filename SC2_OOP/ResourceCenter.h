#pragma once
#ifndef _RESOURCE_CENTER_H
#define _RESOURCE_CENTER_H

#include "GameObject.h"

class Resource;

class ResourceCenter : public GameObject{
public:
	//constructors and destructor
	ResourceCenter();
	ResourceCenter(ResourceCenter &r);
	virtual ~ResourceCenter();

	//methods
	void obtain(Resource *r);
};

#endif