#pragma once
#include "IProcessor.h"
#include "string"



class Processor_BC : public IProcessor
{
public:
	static enum whatToDo { dot_to_coma = 0, dot_to_noth = 1 };
	Processor_BC(int);
	void process(std::string, std::string) override;
};