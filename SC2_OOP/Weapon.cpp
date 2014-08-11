#include "Weapon.h"
#include "GameObject.h"

Weapon::Weapon(){
	name = NULL;
	damage = NULL;
	modifier = NULL; 
	range = NULL;
	cooldown = NULL;
}

Weapon::~Weapon(){
}

string Weapon::getNameValue(){
	return *name;
}

float Weapon::getDamageValue(){
	return *damage;
}

float Weapon::getModifierValue(){
	return *modifier;
}

float Weapon::getRangeValue(){
	return *range;
}

float Weapon::getCooldownValue(){
	return *cooldown;
}

string* Weapon::getName(){
	return name;
}

float* Weapon::getDamage(){
	return damage;
}

float* Weapon::getModifier(){
	return modifier;
}

float* Weapon::getRange(){
	return range;
}

float* Weapon::getCooldown(){
	return cooldown;
}

void Weapon::setName(string &name){
	this->name = &name;
}

void Weapon::setDamage(float &damage){
	this->damage = &damage;
}

void Weapon::setModifier(float &modifier){
	this->modifier = &modifier;
}

void Weapon::setRange(float &range){
	this->range = &range;
}

void Weapon::setCooldown(float &cooldown){
	this->cooldown = &cooldown;
}