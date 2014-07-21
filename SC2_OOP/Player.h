#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <vector>

using namespace std;

class World;
class GameObject;

class Player{
public:
	Player();
	Player(string race);
	~Player();

protected:
	World *world;
	vector<GameObject*> objects;

	static string ZERG;
	static string TERRAN;
	static string PROTOSS;
};

#endif