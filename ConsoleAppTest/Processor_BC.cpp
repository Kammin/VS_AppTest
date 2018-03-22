#include "stdafx.h"
#include "Processor_BC.h"
#include "iostream"
#include "string"
#include "fstream"
#include "IProcessor.h"
#include "FileManager.h"
using namespace std;
int flag;

Processor_BC::Processor_BC(int whatToDo) {
	flag = whatToDo;
}

void Processor_BC::process(string file_in, string file_out) {
	std::cout << "process  BC" << endl;
	char ch;
	FileManager fileManager(file_in, file_out);

	try {
		if (!fileManager.fin.is_open() | !fileManager.fout.is_open()) {
			cout << "Error opening the file !" << endl;
		}
		else {
			fileManager.fin.seekg(0, fileManager.fin.end);
			int size = fileManager.fin.tellg();
			cout << "size of file  " << size << endl << "Start..." << endl;
			fileManager.fin.seekg(0, fileManager.fin.beg);
			while (fileManager.fin.get(ch)) {
				if ((ch == '.')&(flag == dot_to_coma))
					ch = ',';
				if ((ch == ' ')&(flag == dot_to_noth))
					continue;
				fileManager.fout << ch;
			}
			std::cout << "processBC finish Ok" << endl;
		}
	}
	catch (const exception& ex) {
		cout << "Error " << ex.what() << endl;
	}
}