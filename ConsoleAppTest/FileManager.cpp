#include "stdafx.h"
#include "FileManager.h"
#include "iostream"
#include "fstream"
using namespace std;

ifstream fin;
ofstream fout;

FileManager::FileManager(string file_in, string file_out) {
	fin.exceptions(ifstream::badbit);
	fout.exceptions(ofstream::badbit | ofstream::failbit);
	try {
		fin.open(file_in);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error opening input file " << file_in << endl;
		cout << "Error code " << ex.what() << endl;
	}
	try {
		fout.open(file_out);
	}
	catch (const ofstream::failure& ex) {
		cout << "Error code " << ex.what() << endl;
	}
}

FileManager::~FileManager(){
	// close fin & fout when destruct
	fin.close();
	fout.close();
}