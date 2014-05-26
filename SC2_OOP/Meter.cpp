#include "Meter.h"
#define NULL 0

Meter::Meter(){
	current = new float(1);
	max = new float(1);
	useDefault = true;
}

Meter::Meter(float &max){
	this->max = &max;
	current = new float(max);
	useDefault = false;
}

Meter::Meter(Meter &m){
	this->current = new float(*m.current);
	this->max = m.max;
	useDefault = false;
}

Meter::~Meter(){
	delete current;
	if(useDefault) delete max;
}

float Meter::getCurrentValue(){
	return *current;
}

void Meter::setCurrent(float val){
	*(this->current) = val;
}

void Meter::setCurrentToMax(){
	*current = *max;
}

void Meter::add(float amount){
	*current += amount;
}

void Meter::subtract(float amount){
	*current -= amount;
}

float Meter::getMaxValue(){
	return *max;
}

void Meter::setMax(float val){
	*max = val;
}

void Meter::linkMax(float &val){
	max = &val;
}

bool Meter::isFull(){
	return (*current == *max);
}