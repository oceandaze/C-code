#include "stdafx.h"
#include "HtmlFile.h"


HtmlFile::HtmlFile()
{
	file.open("123.html");
}


HtmlFile::~HtmlFile()
{
}

void HtmlFile::write(vector<PAIR> v)
{
	file << "<table border = \"1\" style = \"color:red ;font-size: 14px;font-weight:bold\">\n"
		<< "<tr>\n"
		<< "<th>" << "����" << "</th>\n"
		<< "<th>" << "��������" << "</th>\n"
		<< "<th>" << "���в���" << "</th>\n"
		<< "</tr>\n";
		
	for (auto i : v)
	{
		file << "<tr>\n"
			<<"<td>"<< i.first << "</td>\n"
			<< "<td>" << i.second.first <<  "</td>\n"
			<< "<td>" << i.second.second << "</td>\n"
			<< "</tr>\n";
	}
	file
		<<"</table>";
}
