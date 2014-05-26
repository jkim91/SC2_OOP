#include "Shield.h"

Shield::Shield(){
	regen();
}

Shield::Shield(float &max){
	regen();
}

Shield::Shield(Shield &s){
	regen();
}

Shield::~Shield(){
	delete currentCooldown;
}

void Shield::regen(){
	currentCooldown = new float(0.0);
	while(true){
		if(!isFull()){
			if(*currentCooldown == cooldown) add(1);
			else (*currentCooldown)++;
		}
		if(*current > *max) setCurrentToMax();
	}
}