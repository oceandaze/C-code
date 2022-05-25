#include "stdafx.h"
#include "Report.h"
#include <algorithm>

Report::Report()
{
}


Report::~Report()
{
}

void Report::run(const string & path)
{
	ifstream file(path);
	if (!file.is_open()) {
		return;
	}

	string cache;
	string line;
	while (getline(file, line)) {
		cache += line;
	}

	vector<vector<string>> data;
	analyze(cache, data);
	sort(data);
	output(data);
}

void Report::analyze(const string & str, vector<vector<string>>& data)
{
	size_t left = 0, pos;
	string mark1 = "tDJ_ee\"><span class=\"index_1-1";
	string mark2 = "_11uzll\">";
	while ((pos = str.find(mark1, left)) != string::npos) {
		left = pos + mark1.size();

		vector<string> item;
		item.push_back(findField(str, ">", left));
		item.push_back(findField(str, mark2, left));
		item.push_back(findField(str, mark2, left));

		data.push_back(item);
	}
}

void Report::sort(vector<vector<string>>& data)
{
	std::sort(data.begin(), data.end(), [](const vector<string>& a, const vector<string>& b) {
		return stoi(a.at(2)) > stoi(b.at(2));
	});
}

string Report::findField(const string &data, const string & mark, size_t & left) const
{
	string text;
	size_t pos = data.find(mark, left);
	if (pos == string::npos) {
		return text;
	}
	left = pos + mark.size();
	pos = data.find("<", left);
	if (pos == string::npos) {
		return text;
	}

	text = data.substr(left, pos - left);
	left = pos;
	return text;
}
