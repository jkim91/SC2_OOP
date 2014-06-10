#include "Regen.h"
#include "Meter.h"

#define NULL 0

Regen::Regen(){
	m = NULL;
	rate = new float(0.0);
	executeSwitch = false;
}

Regen::Regen(Meter &m, float &rate){
	this->m = &m;
	this->rate = &rate;
	executeSwitch = false;
}

Regen::~Regen(){
	delete rate;
}

Meter* Regen::getMeter(){
	return m;
}

float Regen::getRateValue(){
	return *rate;
}

float* Regen::getRatePointer(){
	return rate;
}

void Regen::setMeter(Meter &m){
	this->m = &m;
}

void Regen::setRate(float rate){
	*(this->rate) = rate;
}

void Regen::switchOn(){
	executeSwitch = true;
}

void Regen::switchOff(){
	executeSwitch = false;
}

void Regen::execute(){
	while (m != NULL){
		if (executeSwitch) break;
		while (!(m->isFull())){
			m->add(*rate);
		}
		if (m->getCurrentValue() > m->getMaxValue()) m->setCurrentToMax();
	}	
}