/*
	A Regen object "fills up" the Meter object, by increasing the current value until it reaches max.

	State, Getters, and Setters
		-rate: rate determines the amount of current to fill per second. Usually rate is not unique, so it is a pointer.
		-cooldown: cooldown represents the amount of time that is required to pass until Meter fills up again
		-interrupt: interrupt is boolean flag to determine if the regen is to be interrupted. If it is, then, it must wait until the coodown has been reached until rate fills up the Meter again.
		-runExec: flag for execution. true keeps the loop going. false stops it.
		-meter: the corresponding Meter object that this Regen object is connected to. Regen object REQUIRES a Meter for existence. It is possible to create a Regen object without a Meter, but Meter MUST be set for it to function. Also, once the Meter is set, the execute algorithm is run. 

	Methods and Functions
		-execute(): Execute() performs the regeneration. It adds rate to the Meter's current until is full. The algorithm can be interrupted and if this is the case, it must wait until cooldown has been reached.
		-switchInterrupt(): This converts the interrupt from true to false or vice versa.
		-stopExecute(): Sets the runExec to false in order to stop the execute() algorithm.

	Constructors
		-Default: should not be used, unless user intends to set the state manually with setters.
		-Copy: Shallow copies rate and cooldown and deep copies interrupt. Meter is NOT copied and set to null. This is OK, as long as meter is set manually by the corresponding meter.
		-Parametrized:
			-rate, cooldown, m: sets the corresponding state and set interrupt to false. execute() algorithm is run.

	Destructor
		-stops the execute algorithm.
*/

#pragma once
#ifndef _REGEN_H
#define _REGEN_H

class Meter;

class Regen{
public:
	Regen(); //not recommended for use
	Regen(Regen &r);
	Regen(float &rate, float &cooldown, Meter &m);
	virtual ~Regen();

	void execute();
	void switchInterrupt();
	void stopExecute();

	float* getRate(); //not recommended for use
	float getRateValue();
	float* getCooldown(); //not recommended for use
	float getCooldownValue();
	bool getInterrupt();
	bool getRunExec();
	Meter* getMeter();

	void setRate(float &f);
	void setCooldown(float &f);
	void setInterrupt(bool val);
	void setRunExec(bool val);
	void setMeter(Meter &m);

	static const bool TRUE = true;
	static const bool FALSE = false;

protected:
	float* rate;
	float* cooldown;
	const bool * interrupt;
	const bool * runExec;

	Meter* meter;
};


#endif