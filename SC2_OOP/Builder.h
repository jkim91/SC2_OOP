#pragma once
#ifndef _BUILDER_H
#define _BUILDER_H

class GameObject;

class Builder{
public:
	virtual void build(GameObject &g) = 0;
	virtual void buildAnimation() = 0;
};

#endif