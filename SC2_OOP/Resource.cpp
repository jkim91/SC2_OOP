#include "Resource.h"
#include "Health.h"
#include "Armor.h"
#include "Meter.h"

Resource::Resource(){
	init();
}

Resource::Resource(string &type, Armor &a){
	name = &type;
	groundStatus = new int(GROUND);
	sightRadius = new int(1);
	health = new Health(*(new int(1)), a);
	attributes = NULL;
	player = NULL;
	useDefault = false;
}

Resource::~Resource(){
	destroy();
}

void Resource::initDetails(){
	amount = new Meter();
}

void Resource::destroyDetails(){
	delete amount;
}

int Resource::getMaxAmount(){
	return amount->getMaxValue();
}

void Resource::setMaxAmount(int &res){
	amount->setMax(res);
}

int Resource::getCurrentAmount(){
	return amount->getCurrentValue();
}

