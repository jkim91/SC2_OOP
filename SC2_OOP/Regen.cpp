#include "Regen.h"
#include "Meter.h"

#define NULL 0

Regen::Regen(){
	m = NULL;
	rate = NULL;
}

Regen::Regen(Meter &m, float &rate){
	this->m = &m;
	this->rate = &rate;
	execute();
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

void Regen::execute(){
	while (m != NULL){
		while (!(m->isFull())){
			m->add(*rate);
		}
		if (m->getCurrentValue() > m->getMaxValue()) m->setCurrentToMax();
	}	
}