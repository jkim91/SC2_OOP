#pragma once
#ifndef _REGEN_H
#define _REGEN_H

/*
	Explanation: Regen fills up a Meter object at a fixed rate. Regen knows its Meter. Meter does not. Does not have a copy constructor.
*/


class Meter;

class Regen{
public:
	Regen(); //default constructor
	Regen(Meter &m, float &rate); //constructor with a Meter object
	virtual ~Regen(); //destructor, does not delete the meter

	Meter* getMeter(); //get the meter
	float getRateValue(); //get the value of rate
	float* getRatePointer(); //get the rate pointer

	void setMeter(Meter &m); //set the meter to a new one
	void setRate(float rate); //set the rate to a value

	void switchOn(); //turn override on
	void switchOff(); //turn override off

protected:
	Meter *m; //target meter to regenerate
	float *rate; //rate of regeneration (SHARED)
	bool executeSwitch; //execute override switch (UNIQUE)
	void execute(); //execute regeneration
};

#endif