#include "Health.h"
#include "Armor.h"
#include "GameObject.h"

Health::Health(){
	
}

Health::Health(Health &h) : Meter(h){
	armor = h.armor;
	owner = h.owner;
}

Health::Health(float &max_health, Armor * a, GameObject * g){
	current = max_health;
	max = &max_health;
	armor = a;
	owner = g;
}

Health::~Health(){
}

void Health::subtract(float amount){
	current -= amount - armor->getVal();
}

Armor* Health::getArmor(){
	return armor;
}

GameObject* Health::getOwner(){
	return owner;
}

void Health::setArmor(Armor *a){
	armor = a;
}

void Health::setOwner(GameObject *g){
	owner = g;
}