#pragma once
#ifndef _METER_H
#define _METER_H

/*
Explanation:
	A Meter object represents a meter or gauge. It has two states, current and max. Both are floats, but current is a variable and max is a pointer.
	
	State, Getters, and Setters:
		-State
			-Current is a float variable, as this represents the uniqueness of a Meter object from another Meter object.
			-Max is a float pointer because Meters will oftentimes share the same max value. Hence, this will save memory and time, if the max value needs to change.
		-Getters and Setters
			-getMax() is not recommended for use due to safety issues.
	Methods and Functions:
		-There are three methods, add, subtract, and setCurrentToMax. 
			-Add will add a float value to current. 
			-Subtract will subtract will subtract a float value from current.
			-SetCurrentToMax will set the current value to the max value.
		-There is one fuction, isFull. 
			-This function will return a boolean value if the Meter is full, meaning that the current value equals the max value.
	Constructors and Destructors:
		-Constructors
			-The default constructor should not be used. It uses NULL for max and for current.
			-Constructor via float passes a float in via reference for the max pointer and current copies the value of input directly.
			-Copy constructor takes an existing Meter object and copies the max reference and the value of the current for construction.
		-Destructor
			-Destructor by itself does nothing because current is destroyed when the object is destroyed and max is a reference, which may or may not be destroyed, depending on the origin of reference. Subclasses may override this, however.
*/

class Meter{
public:
	Meter();
	Meter(float &max);
	Meter(Meter &m);
	virtual ~Meter();

	//methods
	void add(float amount);
	void subtract(float amount);
	void setCurrentToMax();	

	//functions
	bool isFull();

	//getters
	float getCurrent();
	float* getMax(); //Not recommended for use
	float getMaxValue();

	//setters
	void setCurrent(float val);
	void setMax(float &val);

protected:
	float current;
	float *max;
};

#endif