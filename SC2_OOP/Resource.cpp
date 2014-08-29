#include "Resource.h"

Resource::Resource(){
	amount = 0;
	type = NULL;
}

Resource::Resource(int amount, string &type){
	this->amount = amount;
	this->type = &type;
}

Resource::Resource(Resource &r){
	amount = r.amount;
	type = r.type;
}

Resource::~Resource(){
}

string Resource::getTypeValue(){
	return *type;
}

int Resource::getAmount(){
	return amount;
}

string* Resource::getType(){
	return type;
}

void Resource::setAmount(int amount){
	this->amount = amount;
}

void Resource::setType(string &type){
	this->type = &type;
}