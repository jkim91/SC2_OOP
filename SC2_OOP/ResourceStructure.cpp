#include "ResourceStructure.h"
#include "Meter.h"

ResourceStructure::ResourceStructure(){
	amount = new Meter<int>(STANDARD);
}

ResourceStructure::ResourceStructure(ResourceStructure &r) : GameObject(r){
	amount = new Meter<int>(*r.amount);
}

ResourceStructure::~ResourceStructure(){
	delete amount;
}

void ResourceStructure::subtract(int request){
	amount->subtract(request);
}

void ResourceStructure::giveResource(Worker &w){

}

Meter<int> ResourceStructure::getAmount(){
	return *amount;
}

int ResourceStructure::getCurrentAmount(){
	return amount->getCurrentValue();
}

int ResourceStructure::getMaxAmount(){
	return amount->getMaxValue();
}

void ResourceStructure::setAmount(Meter<int> &m){
	if (amount != NULL) delete amount;
	amount = new Meter<int>(m);
}