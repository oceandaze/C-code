#include "stdafx.h"
#include "MergeFile.h"



MergeFile::MergeFile(const string  str[], int cnt)
{
	ifstream filei;
	for (int i=0;i<cnt;++i)
	{
		filei.open(str[i]);
		string line;
		while (getline(filei,line))
		{
			arr.push_back(line);
		}
		filei.close();
	}

}

MergeFile::~MergeFile()
{
}

void MergeFile::merge()
{
	file.open("merge.txt");
	for (auto i:arr)
	{
		file << i<<"\n";
	}
}
