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
protected:
	float *current; //current value pofloater (UNIQUE)
	float *max; //max value pofloater(SHARED)
	bool useDefault; //check if the object was created using the default constructor
public:
	Meter(); //default constructor, creates a new float for max
	Meter(float &max); //primitive constructor, creates new current from the reference, but max references the parameter
	Meter(Meter &m); //copy constructor, creates current, but references the max of the copy
	virtual ~Meter(); //destructor, deletes only the current, but deletes everything if it used default

	float getCurrentValue(); //getter for current value, for GUI/debugging
	void setCurrent(float val); //setter for current, does not create a new float.
	void setCurrentToMax(); //set the current to max value
	void add(float amount); //add to current amount
	void subtract(float amount); //subtract from current amount

	float getMaxValue(); //getter for max value, for GUI/debugging
	void setMax(float val); //set the max to a new value
	void linkMax(float &val); //link to an float from the parameter
	
	bool isFull(); //check if max is greater than or equal to current

};

#endif