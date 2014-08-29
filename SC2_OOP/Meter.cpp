#include "Meter.h"
#define NULL 0

Meter::Meter(){
	max = NULL;
	current = NULL;
}

Meter::Meter(float &max){
	this->max = &max;
	current = max;
}

Meter::Meter(Meter &m){
	this->max = m.max;
	this->current = m.current;
}

Meter::~Meter(){
}

void Meter::add(float amount){
	current += amount;
}

void Meter::subtract(float amount){
	current -= amount;
}

bool Meter::isFull(){
	return (current >= *max);
}

float Meter::getMaxValue(){
	return *max;
}

float Meter::getCurrent(){
	return current;
}

float* Meter::getMax(){
	return max;
}

void Meter::setCurrent(float val){
	current = val;
}

void Meter::setMax(float &max){
	this->max = &max;
}

void Meter::setCurrentToMax(){
	current = *max;
}
