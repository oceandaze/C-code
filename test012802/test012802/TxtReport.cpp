#include "stdafx.h"
#include "TxtReport.h"


TxtReport::TxtReport()
{
}


TxtReport::~TxtReport()
{
}

void TxtReport::output(vector<vector<string>>& data)
{
	m_out.open("11.txt");
	m_out << "����\t\t\t\t��������\t���в���\n";
	for (const auto &i : data) {
		m_out << i[0] << "\t\t\t\t"
			<< i[1] << "\t\t\t\t"
			<< i[2] << "\n";
	}
	cout << "txt�����������\n" << endl;
}
