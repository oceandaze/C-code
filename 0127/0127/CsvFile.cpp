#include "stdafx.h"
#include "CsvFile.h"


CsvFile::CsvFile()
{
	file.open("123.csv");
}


CsvFile::~CsvFile()
{
}

void CsvFile::write(vector<PAIR> v)
{
	file << "地区" <<","
		<< "新增病例" << ","
		<< "现有病例" << endl;
	for (auto i : v)
	{
		file << i.first <<  ","
			<< i.second.first << ","
			<< i.second.second << endl;
	}
}
