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

class Armor;
class Combat;
class Weapon;
class Transform;
class Player;
class Meter;

class GameObject{
private:
protected:
	void init(); //default constructor method (Template Method)
	virtual void initDetails(); //additonal details to be filled in for init()

	void destroy(); //destructor method (Template Method)
	virtual void destroyDetails(); //additional details to be filled in for destroy()

	string *name; //name of the object, usually the class name (SHARED)
	bool *groundStatus; //status for on the ground or air (UNIQUE)
	float *sightRadius; //sight radius for what the object can "see" (UNIQUE)
	Meter *health; //health (UNIQUE)
	Armor *armor; //armor (SHARED)
	set<string> *attributes; //set of string attributes (SHARED)
	Player *player; //player that owns this gameobject (SHARED)
	bool useDefault; //check if the object was created with the default constructor
public:
	GameObject();
	virtual ~GameObject();
	
	//getter and setter for name of gameobject
	string getName(); //getter for name
	void setName(string &name); //setter for name
	
	bool getGroundStatus(); //getter for status. setter done in subclass constructors.

	float getSightRadius(); //getter for sight radius
	void setSightRadius(float sightRadius); //set the radius to a new value

	Meter* getHealth(); //getter for health pointer
	virtual void addHealth(float amount); //add to the object's current health
	virtual void subHealth(float amount); //subtract from the object's current health
	void setHealth(Meter &h); //setter for health

	Armor* getArmor(); //getter for armor pointer
	void setArmor(Armor &a); //setter for armor

	set<string>* getAttributes(); //getter for all attributes
	void setAttributes(set<string> &s); //setter for attributes

	Player* getPlayer(); //getter for player
	void linkToPlayer(Player &owner); //link to a player

	Transform *transform; //object's transform (UNIQUE)

	//ground or air status
	static const bool GROUND = 0;
	static const bool AIR = 1;

	//complete list of attributes in string
	static const string LIGHT;
	static const string ARMORED;
	static const string BIO;
	static const string MECH;
	static const string DETECTOR;
	static const string MASSIVE;
	static const string PSIONIC;
	static const string STRUCTURE;
};

const string GameObject::LIGHT = "Light";
const string GameObject::ARMORED = "Armored";
const string GameObject::BIO = "Biological";
const string GameObject::MECH = "Mechanical";
const string GameObject::DETECTOR = "Detector";
const string GameObject::MASSIVE = "Massive";
const string GameObject::PSIONIC = "Psionic";
const string GameObject::STRUCTURE = "Structure";

#endif