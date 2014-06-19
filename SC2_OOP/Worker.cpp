#include "Worker.h"
#include "Resource.h"
#include "ResourceStructure.h"
#include "ResourceCenter.h"

Worker::Worker(){
	res = NULL;
}

Worker::Worker(Worker &w){
	res = new Resource(*w.res);
}

Worker::~Worker(){
	if (res != NULL) delete res;
}

void Worker::gather(ResourceStructure &r){
	r.giveResource(*this);
}

Resource Worker::getResource(){
	return *res;
}

void Worker::setResource(Resource *res){
	this->res = res;
}