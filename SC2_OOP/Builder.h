#pragma once
#ifndef _BUILDER_H
#define _BUILDER_H

class Builder{
public:
	Builder();
	virtual void build(string &hash) = 0;
};

#endif