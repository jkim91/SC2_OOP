#pragma once
#ifndef _PHYSICS_H
#define _PHYSICS_H

class Physics{
public:
	static void move(float start[3], float end[3], float init_speed, float max_speed, float accel);
	static void rotate(float start[3], float end[3]);
	static void rotate(float start[4], float end[4]);
};

#endif