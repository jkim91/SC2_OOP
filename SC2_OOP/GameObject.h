#pragma once
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

/*
Explanation:
	GameObject is any object in the game. All objects have a name, groundStatus, sight, health, attributes,transform and the players that owns the object. GameObject should be subclassed to determine what type of object it is.
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
class Health;
class Player;

class GameObject{
private:
protected:
	string *name; //name of the object, usually the class name (SHARED)
	int *groundStatus; //status for on the ground or air (UNIQUE)
	int *sightRadius; //sight radius for what the object can "see" (UNIQUE)
	Health *health; //health (UNIQUE)
	Armor *armor; //armor, but only for testing. subclasses will reference armor inside health
	set<string> *attributes; //set of string attributes (SHARED)
	Player *player; //player that owns this gameobject (SHARED)
public:
	GameObject();
	~GameObject();
	
	//getter and setter for name of gameobject
	string getName(); //getter for name
	void setName(string &name); //setter for name
	
	int getGroundStatus(); //getter for status. setter done in subclass constructors.

	int getSightRadius(); //getter for sight radius
	void setSightRadius(int &sightRadius); //set the radius

	Health *getHealth(); //getter for health pointer
	virtual void addHealth(int amount); //add to the object's current health
	virtual void subHealth(int amount); //subtract from the object's current health
	void setHealth(Health &h); //setter for health

	Armor *getArmor(); //getter for armor pointer
	void setArmor(Armor &a); //setter for armor

	set<string> *getAttributes(); //getter for all attributes
	void setAttributes(set<string> &s); //setter for attributes

	Player *getPlayer(); //getter for player
	void linkToPlayer(Player &owner); //link to a player

	virtual void stop(); //stop the object

	Transform *transform; //object's transform (UNIQUE)

	//ground or air status
	static const int GROUND = 0;
	static const int AIR = 1;

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

#endif