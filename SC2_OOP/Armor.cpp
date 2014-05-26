#include "Armor.h"

Armor::Armor(){
	this->val = 0;
	this->isInvulnerable = 0;
}

Armor:: Armor(float val){
	this->val = val;
	isInvulnerable = 0;
}

Armor::Armor(float val, bool flag){
	this->val = val;
	isInvulnerable = flag;
}

Armor::Armor(Armor &a){
	setVal(a.getVal());
}

float Armor::getVal(){
	return val;
}

void Armor::setVal(float val){
	this->val = val;
}

bool Armor::getIsInvulnerable(){
	return isInvulnerable;
}

void Armor::setIsInvulnerable(bool flag){
	isInvulnerable = flag;
}