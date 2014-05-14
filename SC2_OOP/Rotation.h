#pragma once
#ifndef _ROTATION_H
#define _ROTATION_H

class Rotation{
public:
	Rotation();
	Rotation(Rotation &r);
	Rotation(float euler[3]);
	Rotation(float quaternion[4]);
	~Rotation();

	void convertEulerToQuaternion();
	void convertQuaternionToEuler();

	float euler[3];
	float quaternion[4];
};

#endif