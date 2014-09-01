#include "GameObject.h"
#include "World.h"
#include "Player.h"

Player::Player(){
}

Player::~Player(){
}

void Player::addResource(int amount, string type){
	resources[type] += amount;
}

bool Player::subResource(int amount, string type){
	if (resources[type] >= amount){
		resources[type] -= amount;
		return 1;
	}
	else return 0;
}

int Player::getResourceAmount(string type){
	return resources[type];
}

void Player::addObject(GameObject *g){
	allObjects[g->getNameValue()].push_back(g);
}

void Player::removeObject(GameObject *g){
	map<string, vector<GameObject*> >::iterator it = allObjects.find(g->getNameValue());
	removeObjectFromList(g, it->second);
	removeObjectFromList(g, selectedGroup);
	for(int i=0; i<10; i++){
		removeObjectFromList(g, controlGroup[i]);
	}
}

void Player::selectObject(GameObject *g, int size){
	if(size == 1){
		selectedObject = g;
		if(g->getPlayer() == this){
			determineSubclass(g);
		}
	}
	else{
		selectedGroup.clear();
		for(int i=0; i<size; i++){
			selectedGroup.push_back(&g[i]);
		}
		determineSubclass(selectedGroup[0]);
	}
}

void Player::createControlGroup(int number){
	controlGroup[number] = selectedGroup;
}

void Player::addToControlGroup(int number){
	for(int i=0; i<selectedGroup.size(); i++){
		controlGroup[number].push_back(selectedGroup[i]);
	}
}

string Player::getRaceValue(){
	return *race;
}

map<string, int> Player::getResources(){
	return resources;
}

int Player::getCurrentSupply(){
	return currentSupply;
}

int Player::getMaxSupply(){
	return maxSupply;
}

GameObject* Player::getSelectedObject(){
	return selectedObject;
}

vector<GameObject*> Player::getSelectedGroup(){
	return selectedGroup;
}

vector<GameObject*>* Player::getControlGroups(){
	return controlGroup;
}

map<string, vector<GameObject*> > Player::getAllObjects(){
	return allObjects;
}

string* Player::getRace(){
	return race;
}

World* Player::getWorld(){
	return world;
}

void Player::setResources(map<string, int> &m){
	resources = m;
}

void Player::setCurrentSupply(int amount){
	currentSupply = amount;
}

void Player::setMaxSupply(int amount){
	maxSupply = amount;
}

void Player::setRace(string &race){
	this->race = &race;
}

void Player::setWorld(World* w){
	world = w;
}

void Player::addSupply(int amount, bool isMax){
	if(isMax) maxSupply += amount;
	else currentSupply += amount;
}

void Player::subSupply(int amount, bool isMax){
	if(isMax) maxSupply -= amount;
	else currentSupply -= amount;
}

void Player::removeObjectFromList(GameObject *g, vector<GameObject*> &v){
	for(int i=0; i<v.size(); i++){
		if(v[i] == g){
			v.erase(v.begin()+i);
			break;
		}
	}
}