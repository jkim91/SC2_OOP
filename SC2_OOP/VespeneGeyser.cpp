#include "VespeneGeyser.h"
#include "Resource.h"
#include "GasCollector.h"

VespeneGeyser::VespeneGeyser(){}
VespeneGeyser::VespeneGeyser(VespeneGeyser &g) : ResourceStructure(g){}
VespeneGeyser::~VespeneGeyser(){}

void VespeneGeyser::giveResource(Worker &w){
	if (collector != NULL) ResourceStructure::giveResource(w, 4);
}

Resource* VespeneGeyser::createResource(int amount){
	return new Resource(amount, Resource::GAS);
}

GasCollector VespeneGeyser::getGasCollector(){
	return *collector;
}

void VespeneGeyser::setGasCollector(GasCollector &g){
	collector = &g;
}