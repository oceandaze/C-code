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
	file << "����" <<","
		<< "��������" << ","
		<< "���в���" << endl;
	for (auto i : v)
	{
		file << i.first <<  ","
			<< i.second.first << ","
			<< i.second.second << endl;
	}
}
