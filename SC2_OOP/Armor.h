#ifndef _ARMOR_H
#define _ARMOR_H

/*
Explanation:
	An Armor object is an object that modifies one or several Meter objects. An Armor object is only created by a Player object and all of the GameObjects under Player use this object modify HP, if attacked.

	State, Constants, Getters, and Setters:
		-State
			-name is a string pointer. It determines the name of the Armor object. It is a pointer because Armor objects in different Player objects may share the same name.
			-level is a int. It is determined by the upgrades performed by the Player object.
			-val is a float. It determines the damage offset suffered by the object.
			-isInvulnerable is a const boolean pointer. It determines if the object referencing this Armor can be attacked or not. It can only reference YES or NO in the Armor class.
		-Constants
			-YES represents true for isInvulnerable.
			-NO represents false for isInvulnerable.
		-Getters and Setters
	
*/

#include <string>

using namespace std;

class Armor{
public:
	Armor(); //default constructor
	Armor(string &name); //constructor with name parameter
	Armor(string &name, float val); //constructor with name and armor value parameter
	Armor(string &name, bool &isInvulnerable); //constructor with name and isInvulnerable flag(should be true, to be honest)
	Armor(Armor &a); //copy constructor

	//functions
	string getNameValue();
	bool getIsInvulnerableValue();

	//getters
	string* getName();
	int getLevel();
	float getVal();
	const bool* getIsInvulnerable();
	
	//setters
	void setName(string &name);
	void setLevel(int level);
	void setVal(float val);
	void setIsInvulnerable(const bool &flag);

protected:
	//state
	string* name; //name of armor (SHARED)
	int level; //upgrade level of armor, defaults to zero (UNIQUE)
	float val; //amount of armor points (UNIQUE)
	const bool* isInvulnerable; //is it invulnerable? (SHARED)

	//constant
	static const bool YES; //flag for yes
	static const bool NO; //flag for no
};

#endif