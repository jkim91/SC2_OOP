#include "GasCollector.h"
#include "Armor.h"

Armor GasCollector::ARMOR = Armor((float)1.0);

GasCollector::GasCollector(){

}

GasCollector::GasCollector(Geyser &g){

}

GasCollector::GasCollector(GasCollector &g) : GameObject(g){

}