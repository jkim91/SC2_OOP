#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

using namespace std;

class World;

class Player{
private:
protected:
	World *world;
public:
	Player();
	Player(string race);
	~Player();

	static const string ZERG;
	static const string TERRAN;
	static const string PROTOSS;

};

#endif