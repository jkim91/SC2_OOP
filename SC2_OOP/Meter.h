#pragma once
#ifndef _METER_H
#define _METER_H

/*
Explanation:
	current is unique, because every object will most definitely have a different, current amount.
	max is shared, but can be unique, because the max does not usually change.
	So, the destructor will delete the current int object, but the max will not be. This MUST be done by a third-party.
*/

class Meter{
protected:
	int *current; //current value pointer (UNIQUE)
	int *max; //max value pointer(SHARED)
	bool useDefault; //check if the object was created using the default constructor
public:
	Meter(); //default constructor, creates a new int for max
	Meter(int &max); //primitive constructor, creates new current from the reference, but max references the parameter
	Meter(Meter &m); //copy constructor, creates current, but references the max of the copy
	virtual ~Meter(); //destructor, deletes only the current, but deletes everything if it used default

	int getCurrentValue(); //getter for current value, for GUI/debugging
	void setCurrent(int val); //setter for current, does not create a new int.
	void setCurrentToMax(); //set the current to max value
	void add(int amount); //add to current amount
	void subtract(int amount); //subtract from current amount

	int getMaxValue(); //getter for max value, for GUI/debugging
	void setMax(int val); //set the max to a new value
	void linkMax(int &val); //link to an int from the parameter
	
	bool isFull(); //check if max is greater than or equal to current

};

#endif