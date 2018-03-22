#pragma once
#include "IProcessor.h"
#include "string"

class Processor_A : public IProcessor
{
public:
	void process(std::string, std::string) override;
};

