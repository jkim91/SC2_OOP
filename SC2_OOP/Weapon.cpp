#include "Weapon.h"
#include "GameObject.h"

Weapon::~Weapon(){
	delete name;
	delete damage;
	delete range;
	delete cooldown;
	delete targetType;
	delete owner;
}

void Weapon::attack(GameObject *target){
	target->updateHealth(*damage);
	execute();
}

string Weapon::getName(){
	return *name;
}

void Weapon::setName(string &name){
	this->name = &name;
}

int Weapon::getDamage(){
	return *damage;
}

void Weapon::setDamage(int &damage){
	this->damage = &damage;
}

int Weapon::getRange(){
	return *range;
}

void Weapon::setRange(int &range){
	this->range = &range;
}

float Weapon::getCooldown(){
	return *cooldown;
}

void Weapon::setCooldown(float &cooldown){
	this->cooldown = &cooldown;
}

int Weapon::getTargetType(){
	return *targetType;
}

void Weapon::setTargetType(int &targetType){
	this->targetType = &targetType;
}