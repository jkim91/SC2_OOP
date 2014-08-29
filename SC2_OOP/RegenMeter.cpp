#include "Regen.h"
#include "RegenMeter.h"
#define NULL 0

RegenMeter::RegenMeter(){
	regen = NULL;
	reset = false;
	restore();
}

RegenMeter::~RegenMeter(){
}

void RegenMeter::resetCoolDown(){
	reset = true;
}

Regen* RegenMeter::getRegen(){
	return regen;
}

void RegenMeter::setRegen(Regen &r){
	this->regen = &r;
}

void RegenMeter::setRegen(Regen *r){
	this->regen = r;
}

void RegenMeter::restore(){
	while (regen != NULL){
		if (reset) setCurrent(0.0);
		while (!(isFull())) add(1.0);
		reset = false;
		if (!isFull()) regen->execute(this);
	}
}
