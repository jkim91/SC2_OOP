#include "GameObject.h"
#include "Health.h"

GameObject::GameObject(){
	name = new string;
	groundStatus = new bool;
	sightRadius = new float;
	health = new Health();
	attributes = new set<string>();
	player = NULL;
	useDefault = true;
	initDetails();
}

GameObject::~GameObject(){
	delete sightRadius;
	delete health;
	if (useDefault){
		delete name;
		delete attributes;
	}
	destroyDetails();
}

void GameObject::initDetails(){
	return;
}

void GameObject::destroyDetails(){
	return;
}

string GameObject::getName(){
	return *name;
}

void GameObject::setName(string &name){
	this->name = &name;
}

bool GameObject::getGroundStatus(){
	return groundStatus;
}

float GameObject::getSightRadius(){
	return *sightRadius;
}

void GameObject::setSightRadius(float sightRadius){
	*(this->sightRadius) = sightRadius;
}

Health* GameObject::getHealth(){
	return health;
}

void GameObject::addHealth(float amount){
	health->add(amount);
}

void GameObject::subHealth(float amount){
	health->subtract(amount);
}

void GameObject::setHealth(Health &h){
	delete health;
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