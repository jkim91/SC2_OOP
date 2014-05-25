#include "Shield.h"
#include "Meter.h"
#include "Armor.h"

Shield::Shield(){
	current = new int(1);
	max = new int(1);
	useDefault = true;
}

Shield::Shield(int &max){
	this->max = &max;
	current = new int(max);
	useDefault = false;
}

Shield::Shield(Shield &s){
	this->current = new int(*s.current);
	this->max = s.max;
	useDefault = false;
}

void Shield::regen(){
	if(isFull()) return;
	add(1);
}