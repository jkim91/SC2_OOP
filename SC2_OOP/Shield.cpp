#include "Shield.h"
#include "Meter.h"
#include "Armor.h"

Shield:: Shield(){
	meter = new Meter();
	armor = NULL;
}

Shield::Shield(int max, Armor &armor){
	meter = new Meter(max);
	this->armor = &armor;
}

Shield::Shield(Shield &h){
	meter = new Meter(*(h.getMeter()));
	armor = h.getArmor();
}

Shield::~Shield(){
	delete meter;
}

void Shield::regen(){
	if(meter->isFull()) return;
	*(meter->getCurrentPointer()) += 1;
}