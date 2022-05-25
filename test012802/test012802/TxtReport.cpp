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
	m_out << "地区\t\t\t\t新增本土\t现有病例\n";
	for (const auto &i : data) {
		m_out << i[0] << "\t\t\t\t"
			<< i[1] << "\t\t\t\t"
			<< i[2] << "\n";
	}
	cout << "txt报告生成完成\n" << endl;
}
