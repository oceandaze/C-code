#include "stdafx.h"
#include "CsvReport.h"


CsvReport::CsvReport()
{
}


CsvReport::~CsvReport()
{
}

void CsvReport::output(vector<vector<string>>& data)
{
	m_out.open("11.csv");
	m_out << "����,��������,���в���\n";
	for (const auto &i : data) {
		m_out << i[0] << ","
			<< i[1] << ","
			<< i[2] << "\n";
	}
	cout << "csv�����������\n" << endl;
}
