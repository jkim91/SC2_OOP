#include "ResourceStructure.h"
#include "Meter.h"

ResourceStructure::ResourceStructure(){
	amount = new Meter(STANDARD);
}

ResourceStructure::ResourceStructure(ResourceStructure &r) : GameObject(r){
	amount = new Meter(*r.amount);
}

ResourceStructure::~ResourceStructure(){
	delete amount;
}

void ResourceStructure::subtract(int request){
	amount->subtract(request);
}

Meter* ResourceStructure::getAmount(){
	return amount;
}

int ResourceStructure::getCurrentAmount(){
	return amount->getCurrentValue();
}

int ResourceStructure::getMaxAmount(){
	return amount->getMaxValue();
}

void ResourceStructure::setMaxAmount(Meter &m){
	amount = &m;
}