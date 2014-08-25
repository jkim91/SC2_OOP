#include "GameObject.h"
#include "Health.h"
#include "Armor.h"
#include "Player.h"


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

GameObject::GameObject(){
	name = NULL;
	groundStatus = &GROUND;
	sightRadius = NULL;
	supply = NULL;
	health = new Health();
	attributes = NULL;
	player = NULL;
}

GameObject::GameObject(GameObject &g){
	name = g.name;
	groundStatus = g.groundStatus;
	sightRadius = g.sightRadius;
	supply = g.supply;
	health = new Health(*g.health);
	attributes = g.attributes;
	player = g.player;
}

GameObject::~GameObject(){
	delete health;
}

void GameObject::addHealth(float amount){
	health->add(amount);
}

void GameObject::subHealth(float amount){
	health->subtract(amount);
}

string GameObject::getNameValue(){
	return *name;
}

bool GameObject::getGroundStatusValue(){
	return *groundStatus;
}

float GameObject::getSightRadiusValue(){
	return *sightRadius;
}

int GameObject::getSupplyValue(){
	return *supply;
}

string* GameObject::getName(){
	return name;
}

bool* GameObject::getGroundStatus(){
	return groundStatus;
}

float* GameObject::getSightRadius(){
	return sightRadius;
}

int* GameObject::getSupply(){
	return supply;
}

Health* GameObject::getHealth(){
	return health;
}

Armor* GameObject::getArmor(){
	return health->getArmor();
}

set<string>* GameObject::getAttributes(){
	return attributes;
}

Player* GameObject::getPlayer(){
	return player;
}

void GameObject::setName(string &name){
	this->name = &name;
}

void GameObject::setSightRadius(float &sightRadius){
	this->sightRadius = &sightRadius;
}

void GameObject::setGroundStatus(bool &status){
	if (&status != &GROUND || &status != &AIR) return;
	groundStatus = &status;
}

void GameObject::setSupply(int &supply){
	this->supply = &supply;
}

void GameObject::setHealth(Health &h){
	if (health != NULL) delete health;
	health = new Health(h);
}

void GameObject::setArmor(Armor &a){
	if (health == NULL) return;
	health->setArmor(a);
}

void GameObject::setAttributes(set<string> &s){
	attributes = &s;
}

void GameObject::setPlayer(Player &p){
	player = &p;
}

