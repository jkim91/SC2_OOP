#include "ResourceFragment.h"

ResourceFragment::ResourceFragment(){
	amount = 0;
	type = NULL;
}

ResourceFragment::ResourceFragment(int amount, string &type){
	this->amount = amount;
	this->type = &type;
}

ResourceFragment::ResourceFragment(ResourceFragment &r){
	amount = r.amount;
	type = r.type;
}

ResourceFragment::~ResourceFragment(){
}

string ResourceFragment::getTypeValue(){
	return *type;
}

int ResourceFragment::getAmount(){
	return amount;
}

string* ResourceFragment::getType(){
	return type;
}

void ResourceFragment::setAmount(int amount){
	this->amount = amount;
}

void ResourceFragment::setType(string &type){
	this->type = &type;
}