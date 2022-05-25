#pragma once
class File
{
public:
	File(const char *n);
	void write(const char *c);
	~File();
private:
	FILE *p;
};

