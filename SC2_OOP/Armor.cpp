#include "Armor.h"

Armor::Armor(){
	this->val = 0;
	this->isInvulnerable = 0;
}

Armor:: Armor(float val){
	this->val = val;
	isInvulnerable = 0;
}

Armor::Armor(bool flag){
	this->val = 0;
	isInvulnerable = flag;
}

Armor::Armor(Armor &a){
	setVal(a.getVal());
	setIsInvulnerable(a.getIsInvulnerable());
}

float Armor::getVal() const{
	return val;
}

void Armor::setVal(float val){
	this->val = val;
}

bool Armor::getIsInvulnerable() const{
	return isInvulnerable;
}

void Armor::setIsInvulnerable(bool flag){
	isInvulnerable = flag;
}