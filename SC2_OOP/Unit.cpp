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

bool Unit::stop(){
	movement->stop();
}

bool Unit::move(float position[3]){
	//TODO
}

bool Unit::patrol(float position[3]){
	//TODO
}

bool Unit::hold(){
	stop();
	//TODO
}

Kinematics_2D* Unit::getMovement() const{
	return movement;
}

void Unit::setMovement(Kinematics_2D &k){
	movement = new Kinematics_2D(k);
}