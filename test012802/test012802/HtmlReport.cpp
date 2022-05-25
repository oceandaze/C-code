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
		<< "<tr><th>����</th>"
		<< "<th>��������</th>"
		<< "<th>���в���</th>"
		<< "</tr>\n";

	for (const auto &i : data) {
		m_out << "<tr>\n"
			<< "<td>" << i[0] << "</td>\n"
			<< "<td>" << i[1] << "</td>\n"
			<< "<td>" << i[2] << "</td>\n"
			<< "</tr>\n";
	}

	m_out << "</table>\n";

	cout << "html�����������\n" << endl;
}
