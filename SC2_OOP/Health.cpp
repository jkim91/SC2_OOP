#include "Health.h"
#include "Meter.h"
#include "Armor.h"

Armor DEFAULT_ARMOR = Armor();

Health::Health(){
	meter = Meter<float>();
	armor = &DEFAULT_ARMOR;
}

Health::Health(Meter<float> &m, Armor &a){
	meter = Meter<float>(m);
	armor = &a;
}

Health::Health(Health &h){
	meter = Meter<float>(h.meter);
	armor = h.armor;
}

Health::~Health(){
}

Meter<float> Health::getMeter(){
	return meter;
}

Armor Health::getArmor(){
	return *armor;
}

void Health::setMeter(Meter<float> &m){
	meter = Meter<float>(m);
}

void Health::setArmor(Armor &a){
	armor = &a;
}