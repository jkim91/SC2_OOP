#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class World;
class GameObject;

class Player{
public:
	Player();
	Player(string &race);
	~Player();

	//abstract methods
	virtual void initObjects() = 0; //initialize player's objects onto World

	//methods
	void initResources();
	void addResource(int amount, string type);
	void subResource(int amount, string type);
	int getResource(string type);
	void createControlGroup(int number); //create control group with selectedObjects, previous control group overwritten
	void addToControlGroup(int number); //add to control group with selectedObjects
	string getRaceValue(); //get race description

	//getters
	map<string, int> getResources();
	int getCurrentSupply();
	int getMaxSupply();
	string* getRace();
	World* getWorld();

	//setters
	void setResources(map<string, int> m);
	void setCurrentSupply(int amount);
	void setMaxSupply(int amount);
	void setRace(string &race);
	void setWorld(World *w);

protected:
	//functions
	void addSupply(int amount, bool isMax); //add supply to current
	void subSupply(int amount, bool isMax); //subtract supply from current
	
	//state
	map<string, int> resources; //BST to map resource types with amount of resource
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