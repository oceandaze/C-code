#include "stdafx.h"
#include "TxtFile.h"
#include <iomanip>


TxtFile::TxtFile()
{
	file.open("123.txt");
}


TxtFile::~TxtFile()
{
}

void TxtFile::write(vector<PAIR> v)
{
	file  << "����				"
		 << "��������			"
		<< "���в���" << endl;
	for (auto i:v)
	{
		file  << i.first << "				"
			<< i.second.first << "			"
			 << i.second.second << endl;
	}
}
