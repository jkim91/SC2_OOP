#include "VespeneGeyser.h"
#include "Resource.h"
#include "GasCollector.h"
#include "Worker.h"

string VespeneGeyser::NAME = "Vespene Geyser";
string VespeneGeyser::TYPE = "Vespene Gas";

VespeneGeyser::VespeneGeyser(){
	name = &NAME;
}

VespeneGeyser::VespeneGeyser(VespeneGeyser &g) : Geyser(g){
}

VespeneGeyser::~VespeneGeyser(){
}

void VespeneGeyser::giveResource(Worker &w){
	if (collector != NULL && collector->getPlayer() == w.getWorkerOwner()) ResourceStructure::giveResource(w, 4);
}

Resource* VespeneGeyser::createResource(int amount){
	return new Resource(amount, TYPE);
}
