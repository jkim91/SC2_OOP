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
public:
	Meter(); //default constructor
	Meter(int max); //primitive constructor, creates both current and max int objects
	Meter(Meter &m); //copy constructor, creates current, but references the max of the copy
	~Meter(); //destructor

	int* getCurrentPointer(); //getter for current pointer, for modification
	int getCurrentValue(); //getter for current value, for GUI/debugging
	void setCurrent(int val); //setter for current, does not create new int.

	int* getMaxPointer(); //getter for max pointer, for modification
	int getMaxValue(); //getter for max value, for GUI/debugging
	void setMax(int val); //set the max to new value
	void linkMax(int &val); //link to an int from the parameter
	bool isFull(); //check if max is equal to current

};

#endif