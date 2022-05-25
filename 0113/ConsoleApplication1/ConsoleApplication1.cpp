// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <list>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;


void exec(const string &sql)
{
	cout << "执行：" << sql << endl;
}
int main1()
{
	ostringstream stream;
	stream << "select *from t_user where id=" << 1;
	cout << stream.str() << endl;//获取数据
	exec(stream.str());

	stream.str("");//清空数据
	stream << "update t_user set h=" << 15.6;
	cout << stream.str() << endl;
	exec(stream.str());
    return 0;
}


int main2()
{
	string str = "小明 男 22 179.65";
	istringstream stream(str);
	string name, sex;
	int age;
	double height;
	stream >> name >> sex >> age >> height;
	cout << "姓名：" << name << "\n"
		<< "性别：" << sex << "\n"
		<< "年龄：" << age << "\n"
		<< "身高：" << height << "\n";
	return 0;
}

int main3() 
{
	cout << setiosflags(ios::right) << setw(27)<<"woaibiejingtiananmen\n" << setw(27) <<"jhasdash\n";

	cout << resetiosflags(ios::left)

	<< setfill('.') << setw(30)<<"hello\n";

	cout << setfill(' ') << setw(30) << "world\n";

	cout << setiosflags(ios::showpos) << 2 << endl;

	cout << resetiosflags(ios::showpos) << +2 << endl;
	cout << setiosflags(ios::showpoint) << 12.5 << endl;
	cout << resetiosflags(ios::showpoint) << 12.500 << endl;

	cout << setiosflags(ios::scientific) << 1e2 << endl;
	cout << resetiosflags(ios::scientific) << 1e2 << endl;

	cout << setprecision(18) << 1.245689922332<<endl;
	cout << setprecision(6) << 1.245689922332 << endl;

	cout << oct << 15<<endl;
	cout << hex << 20<<endl;

	return 0;
}

int main4()
{
	list<int> l1 = { 3,-100 };
	l1.push_back(2);
	l1.push_front(300);
	cout << "l1.size() =" << l1.size() << endl;
	cout << " l1.empty() =" << l1.empty() << endl;
	  for (auto iter =l1.begin();iter!=l1.end();++iter)
	  {
		  cout << *iter << " ";
	  }
	  cout << endl;
	  for (auto &i:l1)
	  {
		  cout << i << " ";
	  }
	  cout << endl;
	  l1.sort();
	  for (auto &i : l1)
	  {
		  cout << i << " ";
	  }
	  cout << endl;
	  l1.sort(greater<int>());
	  for (auto &i : l1)
	  {
		  cout << i << " ";
	  }
	  cout << endl;
	  //sort(l1.begin(), l1.end(),less<int>());
	 // sort(l1.rbegin(), l1.rend());
	return 0;
}

int main5()
{
	int n;
	int m;
	while (cin >> n >> m)
	{
		cout << n << m<<endl;
	}
	return 0;
}
bool isNum(string s) {
	stringstream sin(s);
	int t;
	char c;
	if (!(sin>>t))
	{
		return false;
	}
	if (sin>>c)
	{
		return false;
	}
	return true;
}
int main()
{
	string str = "A10;S20;W10;D30;X;A1A;B10A11;;A10;A1";
	size_t i = str.find(';');
	while (i!=string::npos)
	{
		str[i] = ' ';
		i = str.find(';');
	}
	istringstream is(str);
	string s;
	int x = 0;
	int y = 0;
	while (is >> s){
		//string ss = "ADWS";
		if (s.size()<4&&isNum(s.substr(1))){
			int num = stoi(s.substr(1));
			if (s[0]=='A'){
				x -= num;
			}	
			else if (s[0] == 'D'){
				x += num;
			}
			else if (s[0] == 'W') {
				y += num;
			}
			else if (s[0] == 'S') {
				y -= num;
			}
		}	
	}
	cout << x << "," << y << endl;
	return 0;
}