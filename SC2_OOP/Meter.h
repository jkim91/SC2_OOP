#pragma once
#ifndef _METER_H
#define _METER_H

/*
Explanation:
	current is unique, because every object will most definitely have a different, current amount.
	max is shared, but can be unique, because the max does not usually change.
	So, the destructor will delete the current float object, but the max will not be. This MUST be done by a third-party.
*/

class Meter{
public:
	Meter(); //default constructor, creates a new float for max (use only for testing)
	Meter(float &max); //primitive constructor, creates new current from the reference, but max references the parameter
	Meter(Meter &m); //copy constructor, creates current, but references the max of the copy
	virtual ~Meter(); //destructor, deletes only the current, but deletes everything if it used default

	float getCurrentValue(); //getter for current value, for GUI/debugging
	void setCurrent(float val); //setter for current, does not create a new float.
	void setCurrentToMax(); //set the current to max value
	void add(float amount); //add to current amount
	void subtract(float amount); //subtract from current amount

	float getMaxValue(); //getter for max value, for GUI/debugging
		
	bool isFull(); //check if current is greater than or equal to max
	bool isEmpty(); //check if current is less than or equal to 0.0

protected:
	float current; //current value pointer (UNIQUE)
	float *max; //max value pointer(SHARED)
	static float MAX_DEFAULT; //default max value

};

float Meter::MAX_DEFAULT = 1.0;

#endif