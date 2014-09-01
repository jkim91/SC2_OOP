#include "ResourceCenter.h"
#include "Player.h"
#include "Resource.h"

ResourceCenter::ResourceCenter(){
}

ResourceCenter::ResourceCenter(ResourceCenter &r){
}

ResourceCenter::~ResourceCenter(){
}

void ResourceCenter::obtain(Resource *r){
	getCenterOwner()->addResource(r->getAmount(), r->getTypeValue());
	delete r;
	r = NULL;
}