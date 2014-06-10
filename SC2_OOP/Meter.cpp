#include "Meter.h"

Meter::Meter(){
	max = &MAX_DEFAULT;
	current = MAX_DEFAULT;
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

float Meter::getCurrentValue(){
	return current;
}

void Meter::setCurrent(float val){
	this->current = val;
}

void Meter::setCurrentToMax(){
	current = *max;
}

void Meter::add(float amount){
	current += amount;
}

void Meter::subtract(float amount){
	current -= amount;
}

float Meter::getMaxValue(){
	return *max;
}

bool Meter::isFull(){
	return (current >= *max);
}

bool Meter::isEmpty(){
	return (current <= 0.0);
}