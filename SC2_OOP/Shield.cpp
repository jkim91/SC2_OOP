#include "Shield.h"
#include "Meter.h"
#include "Armor.h"

Shield::Shield(){
	meter = new Meter();
	armor = new Armor();
	useDefault = true;
}

Shield::Shield(int &max, Armor &armor){
	meter = new Meter(max);
	this->armor = &armor;
	useDefault = false;
}

Shield::Shield(Shield &h){
	meter = new Meter(*(h.getMeter()));
	armor = h.getArmor();
	useDefault = false;
}

Shield::~Shield(){
	delete meter;
	if(useDefault) delete armor;
}

void Shield::regen(){
	if(meter->isFull()) return;
	*(meter->getCurrentPointer()) += 1;
}