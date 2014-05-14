#pragma once
#ifndef _ABILITY_H
#define _ABILITY_H

class GameObject;

class Ability{
public:
	virtual void execute() = 0;
};

#endif