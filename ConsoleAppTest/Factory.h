#include "stdafx.h"
#include "string"
#include "IProcessor.h"
using namespace std;

class Factory
{
public:
	Factory(IProcessor&);
	~Factory();
	void process(string, string);
};