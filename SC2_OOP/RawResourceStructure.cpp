#include "RawResourceStructure.h"
#include "Resource.h"
#include "ResourceRefiner.h"

RawResourceStructure::RawResourceStructure(){
	refiner = NULL;
}

RawResourceStructure::RawResourceStructure(RawResourceStructure &g) : ResourceStructure(g){
	refiner = NULL;
}

RawResourceStructure::~RawResourceStructure(){
	if (refiner != NULL) delete refiner;
}

ResourceRefiner* RawResourceStructure::getRefiner(){
	return refiner;
}

void RawResourceStructure::setRefiner(ResourceRefiner *g){
	refiner = g;
}