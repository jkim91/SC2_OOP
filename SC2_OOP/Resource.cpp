#include "Resource.h"
#include "Health.h"
#include "Armor.h"
#include "Meter.h"

void Resource::initDetails(){
	amount = new Meter();
}

void Resource::destroyDetails(){
	delete amount;
}

Resource::Resource(){
	init();
}

Resource::Resource(string &type){
	name = &type;
	groundStatus = new int(GROUND);
	sightRadius = new int(1);
	health = new Health();
	armor = new Armor();
	attributes = NULL;
	player = NULL;
	useDefault = false;
}

Resource::~Resource(){
	destroy();
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

