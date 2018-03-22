#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
#include "Processor_A.h"
#include "IProcessor.h"
#include "FileManager.h"
using namespace std;


void Processor_A::process(string file_in, string file_out) {
	std::cout << "process  A" << endl;
	string word = "";

	FileManager fileManager(file_in, file_out);
	try {
		if (!fileManager.fin.is_open() | !fileManager.fout.is_open()) {
			cout << "Error opening the file !" << endl;
		}
		else {
			fileManager.fin.seekg(0, fileManager.fin.end);
			int size = fileManager.fin.tellg();
			cout << "size of file  " << size << endl << "Start..." << endl;
			size++;
			fileManager.fin.seekg(0, fileManager.fin.beg);
			while (!fileManager.fin.eof()) {
				fileManager.fin >> word;
				size -= word.length() + 1;
				fileManager.fout.seekp(size);
				fileManager.fout << word;
			}
			std::cout << "processA finish Ok" << endl;
		}
	}
	catch (const exception& ex) {
		cout << "Error " << ex.what() << endl;
	}

}


