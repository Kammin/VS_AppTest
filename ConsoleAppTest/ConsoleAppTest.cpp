// ConsoleAppTest.cpp : Defines the entry point for the console application.
// please safe your eyes when read this code 

#include "stdafx.h"
#include "IProcessor.h"
#include "Processor_A.h"
#include "Processor_BC.h"
#include "Factory.h"
#include "string"
#include "iostream"
#include "fstream"
using namespace std;

const string FileNameIn = "example.txt";
const string FileNameOut = "example_out.txt";


int main(int argc, char* argv[])
{
	// algorothm A if argv is clear
	char arg_ch = 'A';
	// get arg 
	if (argc > 1) {
		arg_ch = argv[1][0];
		cout << "input argument\t" << arg_ch << endl;
	}

	switch (arg_ch) {
	case 'a':
	case 'A': {
		/*create object of Processor_A, that implements the interface IProcessor 
		through a virtual method process(FileNameIn, FileNameOut)*/
		Processor_A processor_A;
		/*create object of Factory with link to processor_A*/
		Factory factory(processor_A);
		//  call factory.process which actually start the processing
		factory.process(FileNameIn, FileNameOut);
		break;
	}
	case 'b':
	case 'B': {
		Processor_BC processor_BC(Processor_BC::dot_to_coma);
		Factory factory(processor_BC);
		factory.process(FileNameIn, FileNameOut);
		break;
	}
	case 'c':
	case 'C': {
		Processor_BC processor_BC(Processor_BC::dot_to_noth);
		Factory factory(processor_BC);
		factory.process(FileNameIn, FileNameOut);
		break;
	}
	default:
		cout << "Invalid input of arguments\n";
		return 0;
	}

	cout << endl << endl;
	return 0;
}



