#include "RegenHealth.h"

RegenHealth::RegenHealth(){
}

RegenHealth::RegenHealth(RegenHealth &r) : Health(r){
	rate = r.rate;
}

RegenHealth::RegenHealth(float &max_health, Armor* a, GameObject *g, float &rate) : Health(max_health, a, g){
	this->rate = &rate;
}

void RegenHealth::execute(){
	while (current < *max){
		add(*rate);
	}
	if (current > *max) current = *max;
}

float* RegenHealth::getRate(){
	return rate;
}

float RegenHealth::getRateValue(){
	return *rate;
}

float* RegenHealth::getCooldown(){
	return cooldown;
}

float RegenHealth::getCooldownValue(){
	return *cooldown;
}

void RegenHealth::setRate(float &f){
	rate = &f;
}

void RegenHealth::setCooldown(float &f){
	cooldown = &f;
}