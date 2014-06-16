#pragma once
#ifndef _RESOURCE_CENTER_H
#define _RESOURCE_CENTER_H

#include "GameObject.h"

class Resource;

class ResourceCenter : public GameObject{
public:
	ResourceCenter();
	ResourceCenter(ResourceCenter &r);
	virtual ~ResourceCenter();
	void obtain(Resource *r);
};

#endif