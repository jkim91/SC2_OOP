#include "FusionCutter.h"
#include "GameObject.h"

string FusionCutter::NAME = "Fusion Cutter";
int FusionCutter::DAMAGE = 5;
int FusionCutter::RANGE = 0;
float FusionCutter::COOLDOWN = 1.5;

FusionCutter::FusionCutter(){
	name = &NAME;
	damage = &DAMAGE;
	range = &RANGE;
	cooldown = &COOLDOWN;
	targetType = &GameObject::GROUND;
}

void FusionCutter::execute(){
	//TODO: attack details
}