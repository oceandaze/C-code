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
	m_out << "地区,新增本土,现有病例\n";
	for (const auto &i : data) {
		m_out << i[0] << ","
			<< i[1] << ","
			<< i[2] << "\n";
	}
	cout << "csv报告生成完成\n" << endl;
}
