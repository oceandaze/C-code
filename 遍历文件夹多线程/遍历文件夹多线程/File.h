#pragma once
#include <string>
using namespace std;
class File
{
public:
	File(const string &name,uint64_t size);
	~File();
	friend ostream &operator<<(ostream &out, const File&other);
	bool operator<(const File&other);
private:
	string filename;
	uint64_t filesize;
};

