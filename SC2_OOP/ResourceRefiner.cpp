#include "ResourceRefiner.h"
#include "Armor.h"
#include "RawResourceStructure.h"

float ResourceRefiner::SIGHT = 9.0;
float ResourceRefiner::ARMOR_VALUE = 1.0;

ResourceRefiner::ResourceRefiner(){
	sightRadius = &SIGHT;
	res = NULL;
}

ResourceRefiner::ResourceRefiner(RawResourceStructure &g){
	sightRadius = &SIGHT;
	res = &g;
	g.setRefiner(this);
	initArmor();
}

ResourceRefiner::~ResourceRefiner(){
}

void ResourceRefiner::giveResource(Worker &w){
	res->giveResource(w);
}

RawResourceStructure* ResourceRefiner::getResourceStructure(){
	return res;
}

void ResourceRefiner::setResourceStructure(RawResourceStructure &g){
	res = &g;
}