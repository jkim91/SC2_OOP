#include "Regen.h"
#include "Meter.h"

Regen::Regen(){
	m = 0;
	rate = 0;
}

Regen::Regen(Meter &m, float &rate){
	this->m = &m;
	this->rate = &rate;
	execute();
}

Regen::~Regen(){
	delete m;
	delete rate;
}

void Regen::execute(){
	while(true){
		if(!(m->isFull())){
			m->add(*rate);
		}
		if(m->getCurrentValue > m->getMaxValue()) m->setCurrentToMax();
	}
}