#pragma once
#ifndef _SCV_H
#define _SCV_H

#include "GameObject.h"
#include "Worker.h"
#include "Builder.h"
#include "Combat.h"

class Player;

class SCV : public GameObject, public Worker, public Combat, public Builder{
private:
	Player *player;
public:
	SCV();
	SCV(Player *player);
	~SCV();
};

#endif