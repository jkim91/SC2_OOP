#pragma once
#ifndef _KINEMATICS_2D_H
#define _KINEMATICS_2D_H

class Kinematics_2D{
public:
	Kinematics_2D();
	Kinematics_2D(float &speed, float &accel, float &angspeed, float &angaccel);
	Kinematics_2D(Kinematics_2D &k);
	virtual ~Kinematics_2D();

	//methods
	void stop(); //immediate stop

	//getters
	float getCurrentSpeed();
	float getMaxSpeed();
	float getAccel();
	float getCurrentAngularSpeed();
	float getMaxAngularSpeed();
	float getAngularAccel();

	//setters
	void setMaxSpeed(float &speed);
	void setAccel(float &accel);
	void setMaxAngularSpeed(float &speed);
	void setAngularAccel(float &accel);
	
protected:
	float currentSpeed; //current speed of unit (UNIQUE)
	float *maxSpeed; //maximum speed of unit (SHARED)
	float *accel; //acceleration of unit (SHARED)
	
	float currentAngularSpeed; //current angular speed of unit for rotation (UNIQUE)
	float *maxAngularSpeed; //maximum angular speed of unit (SHARED)
	float *angularAccel; //angular acceleration of unit(SHARED)

	static float ZERO; //zero constant for default constructor
};

float Kinematics_2D::ZERO = 0.0;

#endif