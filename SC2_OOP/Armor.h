#ifndef _ARMOR_H
#define _ARMOR_H

/*
Explanation:
	Armor has three variables, name, level, isInvulnerable flag and the value of armor points.
	name will point to a string within the possible armor name values, so shared.
	level will always be unique, depending on the player, so unique.
	value will always be unique due to level, so unique.
	isInvulnerable will always point to yes or no, within the Armor class.
*/

#include <string>
#include <set>

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
	bool* getIsInvulnerable();
	
	//setters
	void setName(string &name); //pass-by reference because it refers to a class variable
	void setLevel(int level);
	void setVal(float val);
	void setIsInvulnerable(bool &flag); //pass-by reference because it refers to a class variable

protected:
	//state
	string* name; //name of armor (SHARED)
	int level; //upgrade level of armor, defaults to zero (UNIQUE)
	float val; //amount of armor points (UNIQUE)
	bool* isInvulnerable; //is it invulnerable? (SHARED)

	//constant
	static set<string> armorNames; //list of possible armor names
	static bool YES; //flag for yes
	static bool NO; //flag for no
};

#endif