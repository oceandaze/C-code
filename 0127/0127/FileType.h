#pragma once
#include "App.h"
#include <fstream>
using namespace std;
class FileType
{
public:
	FileType();
	~FileType();
	virtual void write(vector<PAIR> v)=0;

protected:
	ofstream file;
};

