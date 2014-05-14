#pragma once
#ifndef _TRANSFORM_H
#define _TRANSFORM_H

class Rotation;

class Transform{
public:
	Transform();
	Transform(Transform &t);
	Transform(float position[3], float rotation[3], float scale[3]);
	Transform(float position[3], float rotation[4], float scale[3]);
	~Transform();

	float position[3];
	float scale[3];
	Rotation *rotation;

};

#endif