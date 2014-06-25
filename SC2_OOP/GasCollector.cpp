#include "GasCollector.h"
#include "Armor.h"
#include "Geyser.h"

float GasCollector::SIGHT = 9.0;
Armor GasCollector::ARMOR = Armor((float)1.0);

GasCollector::GasCollector(){
	sightRadius = &SIGHT;
	geyser = NULL;
}

GasCollector::GasCollector(Geyser &g){
	sightRadius = &SIGHT;
	geyser = &g;
	g.setGasCollector(*this);
}

GasCollector::GasCollector(GasCollector &g) : GameObject(g){
	sightRadius = &SIGHT;
	geyser = g.geyser;
	g.geyser->setGasCollector(*this);	
}

GasCollector::GasCollector(GasCollector &g) : GameObject(g){
	sightRadius = g.sightRadius;
	setGeyser(*g.geyser);
}

GasCollector::~GasCollector(){
}

void GasCollector::giveResource(Worker &w){
	geyser->giveResource(w);
}

Geyser* GasCollector::getGeyser() const{
	return geyser;
}

void GasCollector::setGeyser(Geyser &g){
	geyser = &g;
}