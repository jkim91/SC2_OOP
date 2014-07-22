#include "VespeneGeyser.h"
#include "Resource.h"

string VespeneGeyser::NAME = "Vespene Geyser";

VespeneGeyser::VespeneGeyser(){
	name = &NAME;
}

VespeneGeyser::VespeneGeyser(VespeneGeyser &g) : Geyser(g){}

VespeneGeyser::~VespeneGeyser(){}

void VespeneGeyser::giveResource(Worker &w){
	if (collector != NULL) ResourceStructure::giveResource(w, 4);
}

Resource* VespeneGeyser::createResource(int amount){
	return new Resource(amount, Resource::GAS);
}
