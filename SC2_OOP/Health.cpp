#include "Health.h"
#include "Meter.h"
#include "Armor.h"

Armor DEFAULT_ARMOR = Armor();

Health::Health(){
	meter = new Meter();
	armor = &DEFAULT_ARMOR;
}

Health::Health(Meter &m, Armor &a){
	meter = new Meter(m);
	armor = &a;
}

Health::Health(Health &h){
	meter = new Meter(*h.meter);
	armor = h.armor;
}

Health::~Health(){
	delete meter;
}

Meter* Health::getMeter(){
	return meter;
}

Armor* Health::getArmor(){
	return armor;
}

void Health::setMeter(Meter &m){
	meter = new Meter(m);
}

void Health::setArmor(Armor &a){
	armor = &a;
}