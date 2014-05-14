#include "Meter.h"
#define NULL 0

Meter::Meter(){
	max = NULL;
	current = NULL;
}

Meter::Meter(int max){
	current = new int(max);
}

Meter::Meter(Meter &m){
	this->current = new int(*m.current);
	this->max = m.max;
}

Meter::~Meter(){
	delete current;
}

int* Meter::getCurrentPointer(){
	return current;
}

int Meter::getCurrentValue(){
	return *current;
}

void Meter::setCurrent(int val){
	*(this->current) = val;
}

int* Meter::getMaxPointer(){
	return max;
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
	return (*current == *max);
}