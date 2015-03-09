#include "Armor.h"

Armor::Armor(){
	name = NULL;
	level = 0;
	val = 0.0;
	isInvulnerable = &NO;
}

Armor::Armor(string &name){
	this->name = &name;
	level = 0;
	val = 0.0;
	isInvulnerable = &NO;
}

Armor:: Armor(string &name, float val){
	this->name = &name;
	level = 0;
	this->val = val;
	isInvulnerable = &NO;
}

Armor::Armor(Armor &a){
	name = a.name;
	level = a.level;
	val = a.val;
	setIsInvulnerable(*a.isInvulnerable);
}

string Armor::getNameValue(){
	return *name;
}

bool Armor::getIsInvulnerableValue(){
	return *isInvulnerable;
}

string* Armor::getName(){
	return name;
}

int Armor::getLevel(){
	return level;
}

float Armor::getVal(){
	return val;
}

const bool* Armor::getIsInvulnerable(){
	return isInvulnerable;
}

void Armor::setName(string &name){
	this->name = &name;
}

void Armor::setLevel(int level){
	this->level = level;
}

void Armor::setVal(float val){
	this->val = val;
}

void Armor::setIsInvulnerable(bool flag){
	if(flag) isInvulnerable = &YES;
	else isInvulnerable = &NO;
}