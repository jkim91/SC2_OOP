#include "RegenHealth.h"

RegenHealth::RegenHealth(){
}

RegenHealth::RegenHealth(RegenHealth &r) : Health(r){
	rate = r.rate;
	cooldown = r.cooldown;
}

RegenHealth::RegenHealth(float &max_health, Armor* a, GameObject *g, float &rate, float &cooldown) : Health(max_health, a, g){
	this->rate = &rate;
	this->cooldown = &cooldown;
}

RegenHealth::~RegenHealth(){
	
}
