#include "MineralField.h"
#include "Meter.h"

MineralField::MineralField(){}
MineralField::MineralField(MineralField &m) : ResourceStructure(m){}
MineralField::~MineralField(){}

void MineralField::subtract(){
	amount->subtract(5);
}