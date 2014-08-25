#pragma once
#ifndef _WORLD_H
#define _WORLD_H

class Player;

#include <vector>
#include <string>

using namespace std;

class World{
public:
	//method
	static World* instance();
protected:
private:
	//constructors/destructor
	World();

	//state
	static World* _instance;
	static vector<Player*> players;
	
};

#endif