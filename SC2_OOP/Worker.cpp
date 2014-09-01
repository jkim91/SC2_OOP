#include "Worker.h"
#include "Resource.h"
#include "ResourceStructure.h"
#include "ResourceCenter.h"

Worker::Worker(){
	res = NULL;
}

Worker::Worker(Worker &w){
	if(w.res != NULL) res = new Resource(*w.res);
	else res = NULL;
}

Worker::~Worker(){
	if (res != NULL) delete res;
}

void Worker::gather(ResourceStructure *r){
	r->giveResource(*this);
}

void Worker::dropOff(ResourceCenter *c){
	if(getWorkerOwner() == c->getCenterOwner()) c->obtain(res);
}

Resource* Worker::getResource(){
	return res;
}

void Worker::setResource(Resource *res){
	this->res = res;
}