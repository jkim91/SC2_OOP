#pragma once
#ifndef _REGEN_H
#define _REGEN_H

/*
	Explanation: Regen fills up a Meter object at a fixed rate.
*/


class Meter;

class Regen{
protected:
	Meter *m; //target meter to regenerate
	float *rate; //rate of regeneration
	void execute(); //execute regeneration
public:
	Regen(); //default constructor
	Regen(Meter &m, float &rate); //constructor with a Meter object
	~Regen(); //destructor
};

#endif