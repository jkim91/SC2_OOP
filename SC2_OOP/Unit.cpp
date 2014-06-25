#include "Unit.h"
#include "Kinematics_2D.h"

Unit::Unit(){
	movement = new Kinematics_2D();
}

Unit::Unit(Unit &u){
	movement = new Kinematics_2D(*u.movement);
}

Unit::~Unit(){
	delete movement;
}

void Unit::stop(){
	movement->stop();
}

void Unit::move(float position[3]){
	//TODO
}

void Unit::patrol(float position[3]){
	//TODO
}

void Unit::hold(){
	stop();
	//TODO
}

Kinematics_2D* Unit::getMovement() const{
	return movement;
}

void Unit::setMovement(Kinematics_2D &k){
	movement = new Kinematics_2D(k);
}