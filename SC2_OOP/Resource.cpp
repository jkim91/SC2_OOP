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

Resource::~Resource(){
	destroy();
}

int Resource::getCurrentAmount(){
	return amount->getCurrentValue();
}

void Resource::subtract(int request){
	amount->subtract(request);
}

int Resource::getMaxAmount(){
	return amount->getMaxValue();
}

void Resource::setMaxAmount(int &res){
	amount->setMax(res);
}

