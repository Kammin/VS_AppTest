#pragma once
#include "string"

class IProcessor
{
public:
	virtual void process(std::string, std::string) = 0;
};

