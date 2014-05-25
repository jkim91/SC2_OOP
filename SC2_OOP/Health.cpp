#include "Health.h"
#include "Armor.h"
#include "Meter.h"

Health::Health(){
	current = new int(1);
	max = new int(1);
	useDefault = true;
}

Health::Health(int &max){
	this->max = &max;
	current = new int(max);
	useDefault = false;
}

Health::Health(Health &h){
	this->current = new int(*h.current);
	this->max = h.max;
	useDefault = false;
}

void Health::regen(){
	return;
}