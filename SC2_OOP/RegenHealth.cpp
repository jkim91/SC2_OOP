#include "RegenHealth.h"
#include "Regen.h"

RegenHealth::RegenHealth(){
}

RegenHealth::RegenHealth(RegenHealth &h) : Health(h){
	r = new Regen(*h.getRegen()->getRate(), *h.getRegen()->getCooldown(), this);

}

RegenHealth::RegenHealth(float &max_health, Armor* a, GameObject* g, float &rate, float &cooldown) : Health(max_health, a, g){
	r = new Regen(rate, cooldown, this);
}

RegenHealth::~RegenHealth(){
	delete r;
}

Regen* RegenHealth::getRegen(){
	return r;
}

void RegenHealth::setRegen(Regen* r){
	this->r = new Regen(*r);
}