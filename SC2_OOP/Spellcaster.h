#pragma once
#ifndef _SPELLCASTER_H
#define _SPELLCASTER_H

class Meter;
class Ability;
class GameObject;

class Spellcaster{
public:
	Spellcaster();
	virtual ~Spellcaster();

	virtual void cast(int command, GameObject *target);

protected:
	Meter* energy;
	Ability* abilities[4];
};

#endif