#include "Regen.h"
#include "Meter.h"

#define NULL 0

Regen::Regen(){
	rate = (float) 0.0;
}

Regen::Regen(float &val){
	rate = val;
}

Regen::~Regen(){
}


void Regen::execute(Meter &m){
	while (!(m.isFull())){
		m.add(rate);
	}
	if (m.getCurrent() > m.getMaxValue()) m.setCurrentToMax();
}

void Regen::execute(Meter *m){
	if (m == NULL) return;
	while (!(m->isFull())){
		m->add(rate);
	}
	if (m->getCurrent() > m->getMaxValue()) m->setCurrentToMax();
}

float Regen::getRate(){
	return rate;
}

void Regen::setRate(float rate){
	this->rate = rate;
}
