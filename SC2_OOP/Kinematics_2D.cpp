#include "Kinematics_2D.h"

Kinematics_2D::Kinematics_2D(){
	stop();
	maxSpeed = &ZERO;
	accel = &ZERO;
	maxAngularSpeed = &ZERO;
	angularAccel = &ZERO;
}

Kinematics_2D::Kinematics_2D(float &speed, float &accel, float &angspeed, float &angaccel){
	stop();
	maxSpeed = &speed;
	this->accel = &accel;
	maxAngularSpeed = &angspeed;
	angularAccel = &angaccel;
}

Kinematics_2D::Kinematics_2D(Kinematics_2D &k){
	stop();
	maxSpeed = k.maxSpeed;
	accel = k.accel;
	maxAngularSpeed = k.maxAngularSpeed;
	angularAccel = k.angularAccel;
}

Kinematics_2D::~Kinematics_2D(){
}

void Kinematics_2D::stop(){
	currentSpeed = ZERO;
	currentAngularSpeed = ZERO;
}

float Kinematics_2D::getCurrentSpeed(){
	return currentSpeed;
}

float Kinematics_2D::getMaxSpeed(){
	return *maxSpeed;
}

float Kinematics_2D::getAccel(){
	return *accel;
}

float Kinematics_2D::getCurrentAngularSpeed(){
	return currentAngularSpeed;
}

float Kinematics_2D::getMaxAngularSpeed(){
	return *maxAngularSpeed;
}

float Kinematics_2D::getAngularAccel(){
	return *angularAccel;
}

void Kinematics_2D::setMaxSpeed(float &speed){
	maxSpeed = &speed;
}

void Kinematics_2D::setAccel(float &accel){
	this->accel = &accel;
}

void Kinematics_2D::setMaxAngularSpeed(float &speed){
	maxAngularSpeed = &speed;
}

void Kinematics_2D::setAngularAccel(float &accel){
	angularAccel = &accel;
}