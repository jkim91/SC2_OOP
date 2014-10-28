#pragma once
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

/*
Explanation:
	GameObject is any object in the game. All objects have a name, groundStatus, sight, health, attributes,transform and the players that owns the object. GameObject should be subclassed to determine what type of object it is. It should not be created
	Name: will not change once set, so shared.
	groundStatus: will not change for most units, but it can happen, so unique.
	sightRadius: can be affected by spell, so unique
	health: will most definitely change, so unique
	attribute: will not change once object is created, so shared.
	player: reference to player. Player owns the object.
	Transform: geometry details of objects, so unique. It is public, so programmer must be careful.
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
	
	//methods for unit movement, subclass Unit implements them appropriately
	virtual bool stop(); //stop the unit immediately
	virtual bool move(float* position); //move to a position
	virtual bool patrol(float* position); //patrol from current to destination
	virtual bool hold(); //hold

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