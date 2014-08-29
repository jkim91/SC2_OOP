#include "GameObject.h"
#include "World.h"
#include "Player.h"

Player::Player(){
}

Player::Player(string &race){
}

Player::~Player(){
}

void Player::addResource(int amount, string type){
	resources[type] += amount;
}
void Player::subResource(int amount, string type){
	if (resources[type] - amount >= 0) resources[type] -= amount;
	else return; //should throw an exception
}
int Player::getResource(string type){
	return resources[type];
}

void Player::createControlGroup(int number){

}