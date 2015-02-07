#include "Armor.h"

const bool Armor::YES = true;
const bool Armor::NO = false;

//code to fill in below for armor names (compile-time option)

Armor::Armor(){
	name = NULL;
	level = 0;
	val = 0.0;
	isInvulnerable = &NO;
}

Armor::Armor(string &name){
	setName(name);
	level = 0;
	val = 0.0;
	isInvulnerable = &NO;
}

Armor:: Armor(string &name, float val){
	setName(name);
	level = 0;
	this->val = val;
	isInvulnerable = &NO;
}

Armor::Armor(string &name, bool &flag){
	setName(name);
	level = 0;
	val = 0.0;
	setIsInvulnerable(flag);
}

Armor::Armor(Armor &a){
	setName(*a.name);
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
}

void Armor::setLevel(int level){
	this->level = level;
}

void Armor::setVal(float val){
	this->val = val;
}

void Armor::setIsInvulnerable(const bool &flag){
	if(&flag == &YES || &flag == &NO) isInvulnerable = &flag;
	//should be some code here for exception
}