#pragma once
class File
{
public:
	File(const char * n);
	
	void Write(const char * s);

	void Print();
	File(const File &) = delete;
	
	~File();
	
private:
	FILE * fp;
};

