#include "Health.h"
#include "Meter.h"
#include "Armor.h"

Armor DEFAULT_ARMOR = Armor();

Health::Health(){
	meter = new Meter<float>();
	armor = &DEFAULT_ARMOR;
}

Health::Health(Meter<float> &m, Armor &a){
	meter = new Meter<float>(m);
	armor = &a;
}

Health::Health(Health &h){
	meter = new Meter<float>(*h.meter);
	armor = h.armor;
}

Health::~Health(){
	delete meter;
}

Meter<float>* Health::getMeter(){
	return meter;
}

Armor* Health::getArmor(){
	return armor;
}

void Health::setMeter(Meter<float> &m){
	if (meter != 0) delete meter;
	meter = new Meter<float>(m);
}

void Health::setMeter(Meter<float> *m){
	if (meter != 0) delete meter;
	meter = new Meter<float>(*m);
}

void Health::setArmor(Armor &a){
	armor = &a;
}

void Health::setArmor(Armor *a){
	armor = a;
}