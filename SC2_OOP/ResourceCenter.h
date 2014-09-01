#pragma once
#ifndef _RESOURCE_CENTER_H
#define _RESOURCE_CENTER_H

class Resource;
class Player;

class ResourceCenter{
public:
	//constructors and destructor
	ResourceCenter();
	ResourceCenter(ResourceCenter &r);
	virtual ~ResourceCenter();

	//abstract methods
	virtual Player* getCenterOwner() = 0;

	//methods
	void obtain(Resource *r);
};

#endif