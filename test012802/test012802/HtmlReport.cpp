#include "stdafx.h"
#include "HtmlReport.h"


HtmlReport::HtmlReport()
{
}


HtmlReport::~HtmlReport()
{
}

void HtmlReport::output(vector<vector<string>>& data)
{
	m_out.open("11.html");
	m_out << "<table border=\"1\">"
		<< "<tr><th>地区</th>"
		<< "<th>新增本土</th>"
		<< "<th>现有病例</th>"
		<< "</tr>\n";

	for (const auto &i : data) {
		m_out << "<tr>\n"
			<< "<td>" << i[0] << "</td>\n"
			<< "<td>" << i[1] << "</td>\n"
			<< "<td>" << i[2] << "</td>\n"
			<< "</tr>\n";
	}

	m_out << "</table>\n";

	cout << "html报告生成完成\n" << endl;
}
