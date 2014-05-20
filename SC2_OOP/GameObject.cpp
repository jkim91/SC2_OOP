#include "GameObject.h"
#include "Health.h"
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
	groundStatus = new int;
	sightRadius = new int;
	health = new Health(*(new Meter()), *(new Armor()));
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

int GameObject::getGroundStatus(){
	return *groundStatus;
}

int GameObject::getSightRadius(){
	return *sightRadius;
}

void GameObject::setSightRadius(int sightRadius){
	*(this->sightRadius) = sightRadius;
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