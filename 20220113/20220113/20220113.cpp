// 20220113.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include "Student.h"#include <iostream>using namespace std;
int main1()
{
	string str;
	while (true)
	{
		cout << "请输入一行字符串" << endl;
		getline(cin, str);
		if (str=="quit"){
			break;
		
		}
		else {
			cout << "您输入的是" << str << endl;
		}
			
	}
    return 0;
}


int main2()
{
	
	ofstream file("1.txt");

// 	for (int i=1;i<=9;++i)
// 	{
// 		for (int j=1;j<=i;++j)
// 		{
// 			file << j << "*" << i << "=" << i*j << "	";
// 		}
// 		file << endl;
// 	}
// 	Student	 s1("张三", 18);
// 	Student	 s2("李四", 19);
// 	Student	 s3("王五", 13);
// 	Student	 s4("赵六", 20);
// 	file << s1 << endl
// 		<< s2 << endl
// 		<< s3 << endl
// 		<< s4 << endl;

	return 0;
}

/*
1、编一程序，输入一个路径和数字N，在用户输入的路径下创建N个txt文件，并在将N写入对应的txt文件。
示例：
输入：D:\      3
程序应在“D:\”下创建3个文件，分别是：1.txt、2.txt、3.txt
1.txt中的内容是1
2.txt中的内容是2
3.txt中的内容是3 
*/
int main3()
{
	int N = 0;
	string str;
	cout << "请输入一个路径和数字N" << endl;
	cin >> str>>N;
	for (int i = 1; i <= N; ++i)
	{
		string path = str+to_string(i) + ".txt";
		ofstream file(path);
		file << i;
	}
	return 0;
}

void split(const string &s, const string &sp, vector<string> &v)
{
	size_t left = 0;
	size_t pos = 0;
	while ((pos = s.find(sp, left)) != string::npos)
	{
		v.push_back(s.substr(left, pos - left));
		left = pos + sp.size();
	}
	if (left < s.size())
	{
		v.push_back(s.substr(left));
	}
}

int main()
{
		string str ;
		string sp;
		cout << "请输入姓名 性别 年龄 家乡" << endl;
		cin >> str;
		cout << "请输入分隔符" << endl;
		cin >> sp;
	vector<string> v;
	ofstream file("1.txt");
	split(str, sp, v);
	for (auto i : v)
	{
		file << i << endl;
	}
	return 0;
}