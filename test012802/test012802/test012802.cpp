// test012802.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Report.h"
#include "HtmlReport.h"
#include "CsvReport.h"
#include "TxtReport.h"

int main()
{
	
	int n = 0;
	cout << "��ѡ�񱨸����ͣ�1��txt 2��csv 3��html\n:";
	cin >> n;
	Report *report = nullptr;
	if (n == 1) {
		report = new TxtReport;
	}
	else if (n==2) {
		report = new CsvReport;
	}
	else if (n==3) {
		report = new HtmlReport;
	}

	if (report != nullptr) {
		report->run("C:\\Users\\wh\\Desktop\\new 8.txt");
		delete report;
	}
    return 0;
}

