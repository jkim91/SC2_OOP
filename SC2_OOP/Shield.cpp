#include "Shield.h"
#include "Meter.h"
#include "Regen.h"
#include "Armor.h"

#define NULL 0

Shield::Shield(){
	meter = new Meter();
	regen = new Regen();
	armor = NULL;
}

Shield::Shield(Meter &m, Regen &r, Armor &a){
	meter = new Meter(m);
	regen = new Regen(*meter, *r.getRatePointer());
	armor = &a;
}

Shield::Shield(Shield &s){
	meter = new Meter(*s.meter);
	regen = new Regen(*meter, *(s.regen->getRatePointer()));
	armor = s.armor;
}

Shield::~Shield(){
	delete currentCooldown;
	delete meter;
	meter = NULL;
	delete regen;
}

Meter* Shield::getMeter(){
	return meter;
}

Armor* Shield::getArmor(){
	return armor;
}

Regen* Shield::getRegen(){
	return regen;
}