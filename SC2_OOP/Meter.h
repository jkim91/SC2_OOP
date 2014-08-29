#pragma once
#ifndef _METER_H
#define _METER_H

/*
Explanation:
	current is unique, because every object will most definitely have a different, current amount.
	max is shared because the max does not usually change.
	So, the destructor will delete the current object, but the max will not be.
*/

class Meter{
public:
	Meter(); //default constructor, creates a new float for max (use only for testing)
	Meter(float &max); //primitive constructor, creates new current from the reference, but max references the parameter
	Meter(Meter &m); //copy constructor, creates current, but references the max of the copy
	virtual ~Meter(); //destructor, deletes only the current, but deletes everything if it used default

	//methods
	void add(float amount); //add to current amount
	void subtract(float amount); //subtract from current amount

	//functions
	bool isFull(); //check if current is greater than or equal to max
	float getMaxValue();

	//getters
	float getCurrent(); //getter for current value, for GUI/debugging
	float* getMax(); //getter for max value, for GUI/debugging

	//setters
	void setCurrent(float val); //setter for current, does not create a new object.
	void setMax(float &val);
	void setCurrentToMax(); //set the current to max value		

protected:
	float current; //current value pointer (UNIQUE)
	float *max; //max value pointer(SHARED)
};

#endif