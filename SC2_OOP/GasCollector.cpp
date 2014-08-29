#include "GasCollector.h"
#include "Armor.h"
#include "Geyser.h"

float GasCollector::SIGHT = 9.0;
float GasCollector::ARMOR_VALUE = 1.0;

GasCollector::GasCollector(){
	sightRadius = &SIGHT;
	geyser = NULL;
}

GasCollector::GasCollector(Geyser &g){
	sightRadius = &SIGHT;
	geyser = &g;
	g.setGasCollector(this);
	initArmor();
}

GasCollector::~GasCollector(){
}

void GasCollector::giveResource(Worker &w){
	geyser->giveResource(w);
}

Geyser* GasCollector::getGeyser(){
	return geyser;
}

void GasCollector::setGeyser(Geyser &g){
	geyser = &g;
}