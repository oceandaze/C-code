#include "stdafx.h"
#include "File.h"
#include <iostream>

using namespace std;


File::File(const char * n)
{
	fopen_s(&fp, n, "w+");
}
void File:: Write(const char * s)
{
	fputs(s, fp);
}
void File::Print()
{
	char str[100];
	rewind(fp);
	fgets(str, 100, fp);
	cout << str << endl;
}
File::~File()
{
	fclose(fp);
}

