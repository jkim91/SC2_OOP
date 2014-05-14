#include "GameObject.h"
#include "Health.h"
#include "Armor.h"

const string GameObject::LIGHT = "Light";
const string GameObject::ARMORED = "Armored";
const string GameObject::BIO = "Biological";
const string GameObject::MECH = "Mechanical";
const string GameObject::DETECTOR = "Detector";
const string GameObject::MASSIVE = "Massive";
const string GameObject::PSIONIC = "Psionic";
const string GameObject::STRUCTURE = "Structure";

GameObject::GameObject(){
	name = NULL;
	groundStatus = new int(GameObject::GROUND);
	sightRadius = new int(1);
	armor = new Armor(1);
	health = new Health(1, *armor);
	attributes = NULL;
}

GameObject::~GameObject(){
	if(health != NULL) delete health;
	if(sightRadius != NULL) delete sightRadius;
	if(groundStatus != NULL) delete groundStatus;
	if(armor != NULL) delete armor;
}

string GameObject::getName(){
	return *name;
}

void GameObject::setName(string &name){
	this->name = &name;
}

int GameObject::getGroundStatus(){
	return *groundStatus;
}

int GameObject::getSightRadius(){
	return *sightRadius;
}

void GameObject::setSightRadius(int &sightRadius){
	this->sightRadius = new int(sightRadius);
}

Health* GameObject::getHealth(){
	return health;
}

void GameObject::addHealth(int amount){
	health->addHealth(amount);
}

void GameObject::subHealth(int amount){
	health->subHealth(amount);
}

void GameObject::setHealth(Health &h){
	health = new Health(h);
}

Armor* GameObject::getArmor(){
	return health->getArmor();
}

void GameObject::setArmor(Armor &a){
	health->setArmor(a);
}

set<string>* GameObject::getAttributes(){
	return attributes;
}

void GameObject::setAttributes(set<string> &s){
	this->attributes = &s;
}

Player* GameObject::getPlayer(){
	return player;
}

void GameObject::linkToPlayer(Player &p){
	player = &p;
}