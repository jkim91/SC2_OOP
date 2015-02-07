#pragma once
#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

/*
Explanation:
	GameObject is an object that can interact with a Player object. It can be controlled by the corresponding Player owner.

Instance variables:
	name: string value that usually corresponds with the name of the class.
	levelStatus: boolean value that determines if the object is on the ground(0) or the air(1).
	sightRadius: float value that determines the sight range of the object.
	health: Meter object that contains the HP information of the unit.
	attributes: set of strings that can further modify the object by attacks or spells.
*/

#include <string>
#include <set>

using namespace std;

class Transform;
class Player;
class Armor;
class Meter;

class GameObject{
public:
	GameObject(); //default constructor
	GameObject(GameObject &g); //copy constructor
	virtual ~GameObject(); //destructor
	
	//methods
	void addHealth(float amount); //add to the object's current health
	void subHealth(float amount); //subtract from the object's current health
	
	//value getters
	string getNameValue(); //return name by value
	bool getGroundStatusValue(); //return ground status by value
	float getSightRadiusValue(); //return sight radius by value

	//getters
	string* getName(); //getter for name
	bool* getGroundStatus(); //getter for status 
	float* getSightRadius(); //getter for sight radius
	Meter* getHealth(); //getter for health
	Armor* getArmor(); //getter for armor
	set<string>* getAttributes(); //getter for all attributes
	Player* getPlayer(); //getter for player
	
	//setters	
	void setName(string &name); //setter for name
	void setSightRadius(float &sightRadius); //set the radius to a new value
	void setGroundStatus(bool &status); //set ground status
	void setHealth(Meter &h); //setter for health
	void setArmor(Armor &a); //setter for armor
	void setAttributes(set<string> &s); //setter for attributes
	void setPlayer(Player &owner); //link to a player
	
	//geometry-related objects. all public
	Transform *transform; //object's transform (UNIQUE)

protected:
	string *name; //name of the object, usually the class name (SHARED)
	bool *groundStatus; //status for on the ground or air (SHARED)
	float *sightRadius; //sight radius for what the object can "see" (SHARED)
	Meter *health; // health of gameObject (UNIQUE)
	Armor *armor; //armor of gameObject(SHARED)
	set<string> *attributes; //set of string attributes (SHARED)
	Player *player; //player that owns this gameobject (SHARED)

	//ground or air status
	static bool GROUND;
	static bool AIR;

	//complete list of attributes in string
	static string LIGHT;
	static string ARMORED;
	static string BIO;
	static string MECH;
	static string DETECTOR;
	static string MASSIVE;
	static string PSIONIC;
	static string STRUCTURE;
};

#endif