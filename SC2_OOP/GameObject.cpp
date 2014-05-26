#include "GameObject.h"
#include "Armor.h"
#include "Meter.h"

GameObject::GameObject(){
	init();
}

GameObject::~GameObject(){
	destroy();
}

void GameObject::init(){
	name = new string;
	groundStatus = new bool;
	sightRadius = new float;
	health = new Meter();
	armor = new Armor();
	attributes = new set<string>();
	player = NULL;
	useDefault = true;
	initDetails();
}

void GameObject::initDetails(){
	return;
}

void GameObject::destroy(){
	delete groundStatus;
	delete sightRadius;
	delete health;
	if(useDefault){
		delete name;
		delete attributes;
		delete armor;
	}
	destroyDetails();
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
	return *groundStatus;
}

float GameObject::getSightRadius(){
	return *sightRadius;
}

void GameObject::setSightRadius(float sightRadius){
	*(this->sightRadius) = sightRadius;
}

Meter* GameObject::getHealth(){
	return health;
}

void GameObject::addHealth(float amount){
	health->add(amount);
}

void GameObject::subHealth(float amount){
	health->subtract(amount);
}

void GameObject::setHealth(Meter &h){
	delete health;
	health = new Meter(h);
}

Armor* GameObject::getArmor(){
	return armor;
}

void GameObject::setArmor(Armor &a){
	armor = &a;
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