#ifndef _ARMOR_H
#define _ARMOR_H

#include <string>

using namespace std;

/*
Explanation:
	armor has two variables, isInvulnerable flag and the value of armor points.
	Both of these values will be on the stack, instead on the heap because objects will point to the armor object, not to any of its state (refer to the Meter class for an example). Also, armor will not be dynamically created.
*/

class Armor{
protected:
	bool isInvulnerable; //is it invulnerable? (UNIQUE)
	int val; //amount of armor points (UNIQUE)
public:
	Armor(); //default constructor
	Armor(int val);//primitive constructor, default to false for invulnerable status
	Armor(int val, bool flag); //primitive constructor, with value and flag
	Armor(Armor &a); //copy constructor (Deep copy)

	int getVal(); //getter for value
	void setVal(int val); //setter for val

	bool getIsInvulnerable(); //getter for invulnerable
	void setIsInvulnerable(bool flag); //setter for invulnerable

};

#endif