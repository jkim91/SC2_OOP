#include "Meter.h"
#define NULL 0

template<class T>
Meter<T>::Meter(){
	max = NULL;
	current = NULL;
}

template<class T>
Meter<T>::Meter(T &max){
	this->max = &max;
	current = new T(max);
}

template<class T>
Meter<T>::Meter(Meter<T> &m){
	this->max = m.max;
	this->current = new T(*m.current);
}

template<class T>
Meter<T>::~Meter(){
	if (current != NULL) delete current;
}

template<class T>
void Meter<T>::add(T amount){
	*current += amount;
}

template<class T>
void Meter<T>::subtract(T amount){
	*current -= amount;
}

template<class T>
T Meter<T>::getMaxValue(){
	return *max;
}

template<class T>
bool Meter<T>::isFull(){
	return (*current >= *max);
}

template<class T>
T Meter<T>::getCurrentValue(){
	return *current;
}

template<class T>
void Meter<T>::setCurrent(T val){
	*current = new T(val);
}

template<class T>
void Meter<T>::setCurrentToMax(){
	*current = *max;
}


