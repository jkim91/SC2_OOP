#include "Shield.h"
#include "Meter.h"
#include "Regen.h"
#include "Armor.h"

#define NULL 0

Shield::Shield(){
	regen = NULL;
	coolDown = new Meter<float>(COOLDOWN_LIMIT);
	reset = false;
	restore();
}

Shield::Shield(Meter<float> &m, Armor &a, Regen<float> &r) : Health(m, a){
	regen = &r;
	coolDown = new Meter<float>(COOLDOWN_LIMIT);
	reset = false;
	restore();
}

Shield::Shield(Shield &s) : Health(s){
	regen = s.regen;
	coolDown = new Meter<float>(*s.coolDown);
	reset = false;
	restore();
}

Shield::~Shield(){
	delete coolDown;
}

void Shield::resetCoolDown(){
	reset = true;
}

Regen<float> Shield::getRegen(){
	return *regen;
}

Meter<float> Shield::getCoolDown(){
	return *coolDown;
}

void Shield::setRegen(Regen<float> &r){
	this->regen = &r;
}

void Shield::setCoolDown(Meter<float> &m){
	if (coolDown != 0) delete coolDown;
	coolDown = new Meter<float>(m);
}

void Shield::restore(){
	while (regen != NULL){
		if (reset) coolDown->setCurrent(0.0);
		while (!(coolDown->isFull())) coolDown->add(1.0);
		reset = false;
		if (!(meter->isFull())) regen->execute(*meter);
	}
}
