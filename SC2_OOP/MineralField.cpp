#include "MineralField.h"
#include "Meter.h"
#include "Resource.h"

MineralField::MineralField(){}
MineralField::MineralField(MineralField &m) : ResourceStructure(m){}
MineralField::~MineralField(){}

void MineralField::giveResource(Worker &w){
	ResourceStructure::giveResource(w, 5);
}

Resource* MineralField::createResource(int amount){
	return new Resource(amount, Resource::MINERAL);
}