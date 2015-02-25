#include "Regen.h"
#include "Meter.h"
#define NULL 0

Regen::Regen(){
}

Regen::Regen(Regen &r){
	rate = r.rate;
	cooldown = r.cooldown;
	interrupt = r.interrupt;
	meter = NULL;
}

Regen::Regen(float &rate, float &cooldown, Meter &m){
	this->rate = &rate;
	this->cooldown = &cooldown;
	interrupt = false;
	this->meter = &m;
	execute();
}

void Regen::execute(){
	while (true){
		if(interrupt){
			int temp=0;
			while(temp < *cooldown) temp++;
			interrupt = false;
		}
		else if (meter->getCurrent() >= meter->getMaxValue()) meter->setCurrentToMax();
		else meter->add(*rate);
	}
}

void Regen::switchInterrupt(){
	interrupt = 1-interrupt;
}

float* Regen::getRate(){
	return rate;
}

float Regen::getRateValue(){
	return *rate;
}

float* Regen::getCooldown(){
	return cooldown;
}

float Regen::getCooldownValue(){
	return *cooldown;
}

bool Regen::getInterrupt(){
	return interrupt;
}

Meter* Regen::getMeter(){
	return meter;
}

void Regen::setRate(float &f){
	rate = &f;
}

void Regen::setCooldown(float &f){
	cooldown = &f;
}

void Regen::setInterrupt(bool val){
	interrupt = val;
}

void Regen::setMeter(Meter &m){
	meter = &m;
}