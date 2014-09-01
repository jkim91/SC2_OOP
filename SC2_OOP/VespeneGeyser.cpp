#include "VespeneGeyser.h"
#include "Resource.h"
#include "ResourceRefiner.h"
#include "Worker.h"

string VespeneGeyser::NAME = "Vespene Geyser";
string VespeneGeyser::TYPE = "Vespene Gas";

VespeneGeyser::VespeneGeyser(){
	name = &NAME;
}

VespeneGeyser::VespeneGeyser(VespeneGeyser &g) : RawResourceStructure(g){
}

VespeneGeyser::~VespeneGeyser(){
}

void VespeneGeyser::giveResource(Worker &w){
	if (refiner != NULL && refiner->getPlayer() == w.getWorkerOwner()) ResourceStructure::giveResource(w, 4);
}

Resource* VespeneGeyser::createResource(int amount){
	return new Resource(amount, TYPE);
}
