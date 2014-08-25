#include "MineralField.h"
#include "Meter.h"
#include "Resource.h"

MineralField::MineralField(){
	name = &NAME;
}

MineralField::MineralField(MineralField &m) : ResourceStructure(m){
	name = &NAME;
}

MineralField::~MineralField(){}

void MineralField::giveResource(Worker &w){
	ResourceStructure::giveResource(w, 5);
}

Resource* MineralField::createResource(int amount){
	return new Resource(amount, Resource::MINERAL);
}