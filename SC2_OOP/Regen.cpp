#include "Regen.h"
#include "Meter.h"

#define NULL 0

template<class T>
Regen<T>::Regen(){
	rate = (float) 0.0;
}

template<class T>
Regen<T>::Regen(float &val){
	rate = val;
}

template<class T>
void Regen<T>::execute(Meter<T> &m){
	while (!(m.isFull())){
		m.add(rate);
	}
	if (m.getCurrentValue() > m.getMaxValue()) m.setCurrentToMax();
}

template<class T>
void Regen<T>::execute(Meter<T> *m){
	if (m == NULL) return;
	while (!(m->isFull())){
		m->add(rate);
	}
	if (m->getCurrentValue() > m->getMaxValue()) m->setCurrentToMax();
}

template<class T>
Regen<T>::Regen(float &rate){
	this->rate = rate;
}

template<class T>
Regen<T>::~Regen(){
}

