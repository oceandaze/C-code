#include "stdafx.h"
#include "Infile.h"


Infile::Infile(const string &path)
{
	file.open(path);
	string line;
	cnt = 0;
	while (getline(file,line))
	{
		split(line, ",");
		++cnt;
	}
	
}

void Infile::split(const string &str, const string &sp)
{
	size_t left = 0;
	size_t pos = 0;
	while ((pos = str.find(sp, left)) != string::npos) {
		arr[cnt].push_back(str.substr(left, pos - left+1));
		left = pos + sp.size();
	}
	if (left < str.size()) {
		arr[cnt].push_back(str.substr(left));
	}
}

void Infile::output() const
{
	
	for (int i=0;i<cnt;++i)
	{
		int k = 1;
		cout << i + 1 << ":";
		for (auto j:arr[i])
		{
			cout << k << "=" << j;
			++k;
		}
		cout << endl;
	}
}
