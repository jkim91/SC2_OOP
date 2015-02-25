#pragma once
#ifndef _REGEN_H
#define _REGEN_H

class Meter;

class Regen{
public:
	Regen();
	Regen(Regen &r);
	Regen(float &rate, float &cooldown, Meter &m);

	void execute();
	void switchInterrupt();

	float* getRate();
	float getRateValue();
	float* getCooldown();
	float getCooldownValue();
	bool getInterrupt();
	Meter* getMeter();

	void setRate(float &f);
	void setCooldown(float &f);
	void setInterrupt(bool val);
	void setMeter(Meter &m);

protected:
	float* rate;
	float* cooldown;
	bool interrupt;

	Meter* meter;
};


#endif