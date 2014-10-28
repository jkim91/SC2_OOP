#pragma once
#ifndef _ABILITY_H
#define _ABILITY_H

class GameObject;

class Ability{
public:
	Ability();
	virtual ~Ability();

	//main interface
	virtual void execute() = 0;

	//getter
	GameObject* getOwner();

	//setter
	void setOwner();

protected:
	GameObject *owner;
};

#endif