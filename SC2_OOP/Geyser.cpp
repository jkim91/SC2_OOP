#include "Geyser.h"
#include "Resource.h"
#include "GasCollector.h"

Geyser::Geyser(){
	collector = NULL;
}

Geyser::Geyser(Geyser &g) : ResourceStructure(g){
	collector = NULL;
}

Geyser::~Geyser(){
	if (collector != NULL) delete collector;
}

GasCollector* Geyser::getGasCollector() const{
	return collector;
}

void Geyser::setGasCollector(GasCollector *g){
	collector = g;
}