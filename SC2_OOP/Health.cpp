#include "Health.h"
#include "Armor.h"
#include "Meter.h"

Health::Health(){
	meter = NULL;
	armor = NULL;
}

Health::Health(int max, Armor &a){
	meter = new Meter(max);
	armor = &a;
}

Health::Health(Meter &m, Armor &a){
	meter = new Meter(m);
	armor = &a;
}

Health::Health(Health &h){
	meter = new Meter(*(h.getMeter()));
	armor = h.getArmor();
}

Health::~Health(){
	if(meter != NULL) delete meter;
}

int Health::getCurrent(){
	return meter->getCurrentValue();
}

void Health::addHealth(int amount){
	*(meter->getCurrentPointer()) += amount;
}

void Health::subHealth(int amount){
	*(meter->getCurrentPointer()) -= amount;
}

int Health::getMax(){
	return meter->getMaxValue();
}

void Health::resetHealthToMax(){
	meter->setCurrent(meter->getMaxValue());
}

Meter* Health::getMeter(){
	return meter;
}

void Health::setMeter(Meter &m){
	meter = new Meter(m);
}

Armor* Health::getArmor(){
	return armor;
}

void Health::setArmor(Armor &a){
	armor = &a;
}

void Health::regen(){
	return;
}