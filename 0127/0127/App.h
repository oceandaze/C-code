#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<string, pair<int, int>> PAIR;

class App
{
public:
	App(const string &path);
	~App();
	void output() const;
	void save();
private:
	ifstream file;
	vector<PAIR> v;

};

