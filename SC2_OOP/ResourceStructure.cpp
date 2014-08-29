#include "ResourceStructure.h"
#include "Meter.h"
#include "Armor.h"
#include "Worker.h"

int ResourceStructure::STANDARD = 2500;
float ResourceStructure::SIGHT = 0.0;
string ResourceStructure::ARMOR_NAME = string("Resource Armor");
Armor ResourceStructure::ARMOR = Armor(ARMOR_NAME, true);
Meter ResourceStructure::HEALTH = Meter();
set<string> ResourceStructure::ATTRIBUTES = set<string>();

ResourceStructure::ResourceStructure(){
	sightRadius = &SIGHT;
	attributes = &ATTRIBUTES;
	health = &HEALTH;
	amount = STANDARD;
}

ResourceStructure::ResourceStructure(ResourceStructure &r) : GameObject(r){
	amount = r.amount;
}

ResourceStructure::~ResourceStructure(){
}

void ResourceStructure::giveResource(Worker &w, int request){
	amount -= request;
	w.setResource(createResource(request));
}


int ResourceStructure::getAmount() const{
	return amount;
}

void ResourceStructure::setAmount(int m){
	amount = m;
}