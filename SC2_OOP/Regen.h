#pragma once
#ifndef _REGEN_H
#define _REGEN_H

/*
	Explanation: Regen fills up a Meter object at a fixed rate. Pass in a Meter object of the same type into execute()
*/


template <class T> class Meter;

template <class T>
class Regen{
public:
	Regen(); //default constructor
	Regen(float &rate); //constructor with a Meter object
	virtual ~Regen(); //destructor, does not delete the meter

	//methods
	void execute(Meter<T> &m); //execute regeneration

	//getter
	float getRate(); //get the value of rate

	//setter
	void setRate(float rate); //set the rate to a value

protected:
	float rate; //rate of regeneration (UNIQUE)
};

#endif