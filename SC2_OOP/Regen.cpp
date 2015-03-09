#include "Regen.h"
#include "Meter.h"
#define NULL 0

Regen::Regen(){
	meter = NULL;
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
	interrupt = &FALSE;
	setMeter(m);
}

Regen::~Regen(){
	runExec = &FALSE;
}

//In reality, this algorithm needs to be modified in order to poll for interrupt and let other tasks run.
void Regen::execute(){
	while (*runExec){
		if(*interrupt){
			int temp=0;
			while(temp < *cooldown) temp++;
			interrupt = &FALSE;
		}
		else if (meter->getCurrent() >= meter->getMaxValue()) meter->setCurrentToMax();
		else meter->add(*rate);
	}
}

void Regen::switchInterrupt(){
	if(*interrupt) interrupt = &FALSE;
	else interrupt = &TRUE;
}

void Regen::stopExecute(){
	runExec = &FALSE;
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

bool Regen::getRunExec(){
	return runExec;
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
	if(val) interrupt = &TRUE;
	else interrupt = &FALSE;
}

void Regen::setRunExec(bool val){
	if(val) runExec = &TRUE;
	else runExec = &FALSE;
}

void Regen::setMeter(Meter &m){
	meter = &m;
	runExec = &TRUE;
	execute();
}