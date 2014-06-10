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
class Health;
class Transform;
class Player;
class Meter;

class GameObject{
public:
	GameObject();
	virtual ~GameObject();
	
	//methods
	void addHealth(float amount); //add to the object's current health
	void subHealth(float amount); //subtract from the object's current health

	//getters
	string getName(); //getter for name
	bool getGroundStatus(); //getter for status. 
	float getSightRadius(); //getter for sight radius
	Health* getHealth(); //getter for health pointer
	Armor* getArmor(); //getter for armor pointer
	set<string>* getAttributes(); //getter for all attributes
	Player* getPlayer(); //getter for player
	
	//setters	
	void setName(string &name); //setter for name	
	void setSightRadius(float sightRadius); //set the radius to a new value
	void setHealth(Health &h); //setter for health
	void setArmor(Armor &a); //setter for armor
	void setAttributes(set<string> &s); //setter for attributes
	void linkToPlayer(Player &owner); //link to a player
	
	//geometry-related objects. all public
	Transform *transform; //object's transform (UNIQUE)

protected:
	virtual void initDetails(); //additonal details to be filled in for init()

	virtual void destroyDetails(); //additional details to be filled in for destroy()

	string *name; //name of the object, usually the class name (SHARED)
	bool groundStatus; //status for on the ground or air (UNIQUE)
	float *sightRadius; //sight radius for what the object can "see" (SHARED)
	Health *health; // health of gameObject (UNIQUE)
	set<string> *attributes; //set of string attributes (SHARED)
	Player *player; //player that owns this gameobject (SHARED)
	bool useDefault; //check if the object was created with the default constructor

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

bool GameObject::GROUND = 0;
bool GameObject::AIR = 1;

string GameObject::LIGHT = "Light";
string GameObject::ARMORED = "Armored";
string GameObject::BIO = "Biological";
string GameObject::MECH = "Mechanical";
string GameObject::DETECTOR = "Detector";
string GameObject::MASSIVE = "Massive";
string GameObject::PSIONIC = "Psionic";
string GameObject::STRUCTURE = "Structure";

#endif