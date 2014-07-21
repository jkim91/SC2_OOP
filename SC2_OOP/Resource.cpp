#include "Resource.h"

int Resource::MINERAL = 0;
int Resource::GAS = 1;

Resource::Resource(){
	amount = 0;
	type = 0;
}

Resource::Resource(int amount, int &type){
	this->amount = amount;
	this->type = &type;
}

Resource::Resource(Resource &r){
	amount = r.amount;
	type = r.type;
}

Resource::~Resource(){
}

int Resource::getAmount(){
	return amount;
}

int Resource::getType(){
	return *type;
}

void Resource::setAmount(int amount){
	this->amount = amount;
}

void Resource::setType(int &type){
	this->type = &type;
}