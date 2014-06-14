#include "VespeneGeyser.h"
#include "Meter.h"

VespeneGeyser::VespeneGeyser(){}
VespeneGeyser::VespeneGeyser(VespeneGeyser &g) : ResourceStructure(g){}
VespeneGeyser::~VespeneGeyser(){}

void VespeneGeyser::subtract(){
	amount->subtract(4);
}

VespeneGeyserCollector* VespeneGeyser::getVespeneGeyserCollector(){
	return collector;
}

void VespeneGeyser::setVespeneGeyserCollector(VespeneGeyserCollector &g){
	collector = &g;
}