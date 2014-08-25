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
	Player(string &race);
	~Player();

	//functions
	virtual void initialize() = 0; //initialize player's objects onto World
	void addMineral(int amount); //add to mineral bank
	void subMineral(int amount); //subtract from mineral bank
	void addGas(int amount); //add to gas bank
	void subGas(int amount); //subtract from gas bank
	string getRaceValue(); //get race description
	void createControlGroup(int number); //create control group with selectedObjects, previous control group overwritten
	void addToControlGroup(int number); //add to control group with selectedObjects
	
	//getters
	int getMineral();
	int getGas();
	int getCurrentSupply();
	int getMaxSupply();
	string* getRace();
	World* getWorld();

	//setters
	void setMineral(int amount);
	void setGas(int amount);
	void setCurrentSupply(int amount);
	void setMaxSupply(int amount);
	void setRace(string &race);
	void setWorld(World *w);

protected:
	//functions
	void addSupplyToCurrent(int amount); //add supply to current
	void subSupplyFromCurrent(int amount); //subtract supply from current
	void addSupplyToMax(int amount); //add supply to max
	void subSupplyFromMax(int amount); //subtract supply from max
	
	//state
	int mineral; //current amount of minerals (UNIQUE)
	int gas; //current amount of gas (UNIQUE)
	int currentSupply; //current supply used by Player (UNIQUE)
	int maxSupply; //current max supply for Player (UNIQUE)
	GameObject* selectedObject; //currently selected object (UNIQUE)
	vector<GameObject*> selectedObjects; //currently selected objects by Player (UNIQUE)
	vector<GameObject*> controlGroups[10]; //control groups for player to use (UNIQUE) 
	vector<GameObject> allObjects; //all objects under this player's control (UNIQUE)
	string* race; //string tag for race (SHARED)
	World* world; //the World that the Player is connected to (SHARED)

	//constants
	static int MAX_SUPPLY;
};

#endif