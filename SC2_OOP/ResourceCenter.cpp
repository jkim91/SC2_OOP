#include "ResourceCenter.h"
#include "Player.h"
#include "Resource.h"

ResourceCenter::ResourceCenter(){
}

ResourceCenter::ResourceCenter(ResourceCenter &r) : GameObject(r){
}

ResourceCenter::~ResourceCenter(){
}

void ResourceCenter::obtain(Resource *r){
	//TODO: work on Player object
	//player->addResource(r.getAmount(), r.getType());
	delete r;
	r = NULL;
}