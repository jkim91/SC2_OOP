#include "Shield.h"
#include "Meter.h"
#include "Regen.h"
#include "Armor.h"

#define NULL 0

Shield::Shield(){
	regen = new Regen();
	coolDown = new Meter(COOLDOWN_LIMIT);
}

Shield::Shield(Meter &m, Armor &a, Regen &r){
	meter = new Meter(m);
	armor = &a;
	regen = new Regen(*meter, *r.getRatePointer());
	coolDown = new Meter(COOLDOWN_LIMIT);
}

Shield::Shield(Shield &s) : Health(s){
	regen = new Regen(*meter, *(s.regen->getRatePointer()));
}

Shield::~Shield(){
	delete regen;
}

Regen* Shield::getRegen(){
	return regen;
}

void Shield::setRegen(Regen &r){
	this->regen = &r;
}