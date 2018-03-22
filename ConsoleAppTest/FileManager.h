#include "string"
#include "fstream"
using namespace std;

class FileManager
{
public:
	ifstream fin;
	ofstream fout;
	FileManager(string, string);
	~FileManager();
};

