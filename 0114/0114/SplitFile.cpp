#include "stdafx.h"
#include "SplitFile.h"





SplitFile::SplitFile(const string & path)
{

	file.open(path);
	string line;
	while (getline(file,line))
	{
		arr.push_back(line);
	}

}

SplitFile::~SplitFile()
{
}

void SplitFile::split(int num)
{
	int n = num;
	int j = 1;
	ofstream filei;
	for (int i=0;i<arr.size();++i)
	{
		if (n==num)
		{
			filei.close();
			string path = "7-" + to_string(j++) + ".txt";
			filei.open(path);
			n =0;
		}
		filei << arr[i]<<"\n";
		++n;
	}
}
