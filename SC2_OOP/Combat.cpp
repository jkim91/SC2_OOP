#include "Combat.h"
#include "Armor.h"
#include "GameObject.h"
#include "Weapon.h"
#define NULL 0


Combat::Combat(){
	weapon = NULL;
}

Combat::Combat(Combat &c){
	weapon = c.weapon;
}

Combat::~Combat(){
}

void Combat::attack(GameObject *g){
	g->subHealth(weapon->getDamageValue() - g->getArmor()->getVal());
}

Weapon* Combat::getWeapon(){
	return weapon;
}

void Combat::setWeapon(Weapon &w){
	weapon = &w;
}