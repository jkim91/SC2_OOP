#include "Meter.h"
#define NULL 0

Meter::Meter(){
	current = new int(1);
	max = new int(1);
	useDefault = true;
}

Meter::Meter(int &max){
	this->max = &max;
	current = new int(max);
	useDefault = false;
}

Meter::Meter(Meter &m){
	this->current = new int(*m.current);
	this->max = m.max;
	useDefault = false;
}

Meter::~Meter(){
	delete current;
	if(useDefault) delete max;
}

int Meter::getCurrentValue(){
	return *current;
}

void Meter::setCurrent(int val){
	*(this->current) = val;
}

void Meter::setCurrentToMax(){
	*current = *max;
}

void Meter::add(int amount){
	*current += amount;
}

void Meter::subtract(int amount){
	*current -= amount;
}

int Meter::getMaxValue(){
	return *max;
}

void Meter::setMax(int val){
	*max = val;
}

void Meter::linkMax(int &val){
	max = &val;
}

bool Meter::isFull(){
	return (*current >= *max);
}