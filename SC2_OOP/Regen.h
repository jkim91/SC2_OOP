#pragma once
#ifndef _REGEN_H
#define _REGEN_H

/*
	Explanation: Regen fills up a Meter object at a fixed rate (in float). Pass in a Meter object of the same type into execute()
*/


class Meter;

class Regen{
public:
	Regen(); //default constructor
	Regen(float &rate); //constructor with a parameter for rate
	virtual ~Regen(); //destructor

	//methods
	void execute(Meter &m); //execute regeneration (by reference)
	void execute(Meter *m); //execute regeneration (by pointer)

	//getter
	float getRate(); //get the value of rate

	//setter
	void setRate(float rate); //set the rate to a value

protected:
	float rate; //rate of regeneration (UNIQUE)
};

#endif