#include "stdafx.h"
#include "Factory.h"
#include "IProcessor.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;
IProcessor *proc;


Factory::Factory(IProcessor & process)
{
	proc = &process;
}


Factory::~Factory()
{
}

void Factory::process(string file_in, string file_out)
{
	proc->process(file_in, file_out);
}





