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
	Player(Player &p);
	~Player();

	//abstract methods
	virtual void initObjects() = 0; //initialize player's objects onto World
	virtual void initResources() = 0; //initialize player resources

	//methods
	//methods regarding resources
	void addResource(int amount, string type); //add resource to bank
	bool subResource(int amount, string type); //subtract resource from bank
	int getResourceAmount(string type);

	//methods regarding object creation/destruction
	void addObject(GameObject *g);
	void removeObject(GameObject *g);

	//methods regarding object control
	void selectObject(GameObject *g, int size); //select GameObjects
	void createControlGroup(int number); //create control group with selectedObjects, previous control group overwritten
	void addToControlGroup(int number); //add to control group with selectedObjects
	
	//fetch string form of Player race
	string getRaceValue(); //get race description

	//getters
	map<string, int> getResources();
	int getCurrentSupply();
	int getMaxSupply();
	GameObject* getSelectedObject();
	vector<GameObject*> getSelectedGroup();
	vector<GameObject*>* getControlGroups();
	map<string, vector<GameObject*> > getAllObjects();
	string* getRace();
	World* getWorld();

	//setters
	void setResources(map<string, int> &m);
	void setCurrentSupply(int amount);
	void setMaxSupply(int amount);
	void setRace(string &race);
	void setWorld(World *w);

protected:
	//abstract methods
	virtual void determineSubclass(GameObject *g) = 0; //determine subclass for proper interface

	//methods
	void addSupply(int amount, bool isMax); //add supply to current
	void subSupply(int amount, bool isMax); //subtract supply from current
	void removeObjectFromList(GameObject *g, vector<GameObject*> &v); //remove object from a list

	//state
	map<string, int> resources; //BST to map resource types with amount of resource
	int currentSupply; //current supply used by Player (UNIQUE)
	int maxSupply; //current max supply for Player (UNIQUE)
	GameObject* selectedObject; //currently selected objects (UNIQUE)
	vector<GameObject*> selectedGroup; //currently selected group of objects (UNIQUE)
	vector<GameObject*> controlGroup[10]; //control groups for player to use (UNIQUE) 
	map<string, vector<GameObject*> > allObjects; //all objects under this player's control (UNIQUE)
	string* race; //string tag for race (SHARED)
	World* world; //the World that the Player is connected to (SHARED)

	//constants
	static int MAX_SUPPLY;
};

#endif