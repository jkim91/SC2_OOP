#include "ResourceStructure.h"
#include "Meter.h"
#include "Armor.h"
#include "Worker.h"
#include "Health.h"

Armor ResourceStructure::ARMOR = Armor(true);
Meter<float> ResourceStructure::HEALTH_METER = Meter<float>();

ResourceStructure::ResourceStructure(){
	sightRadius = &SIGHT;
	attributes = &ATTRIBUTES;
	health->setArmor(ARMOR);
	health->setMeter(HEALTH_METER);
	amount = new Meter<int>(STANDARD);
}

ResourceStructure::ResourceStructure(ResourceStructure &r) : GameObject(r){
	amount = new Meter<int>(*r.amount);
}

ResourceStructure::~ResourceStructure(){
	delete amount;
}
void ResourceStructure::giveResource(Worker &w, int request){
	amount->subtract(request);
	w.setResource(createResource(request));
}


Meter<int> ResourceStructure::getAmount(){
	return *amount;
}

int ResourceStructure::getCurrentAmount(){
	return amount->getCurrentValue();
}

int ResourceStructure::getMaxAmount(){
	return amount->getMaxValue();
}

void ResourceStructure::setAmount(Meter<int> &m){
	if (amount != NULL) delete amount;
	amount = new Meter<int>(m);
}