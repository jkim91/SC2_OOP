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
	r.subtract();
	res = r.createResource();
}

void Worker::dropOff(ResourceCenter *g){
	if (g != NULL) g->obtain(res);
}