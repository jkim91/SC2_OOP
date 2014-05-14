#pragma once
#ifndef _LIFT_H
#define _LIFT_H

class Lift{
public:
	virtual void setOnGround();
	virtual void setOnAir();
	virtual void setOnGroundAnimation() = 0;
	virtual void setOnAirAnimation() = 0;
};

#endif