// 021002.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <regex>
#include <ctime>
using namespace std;

mutex g_mutex;//������
condition_variable g_cv;//��������

list<string> g_cache;

//��������
void workThread()
{
	unique_lock<mutex> lk(g_mutex);
	g_cv.wait(lk);//�ȴ���������

	while (!g_cache.empty())
	{
		cout << "�������ݣ�"
			<< g_cache.front() << endl;
		g_cache.pop_front();
	}
	cout << "�����߳����\n";
}

int main()
{
	//thread t1(workThread);

	for (int i=0;i<3;++i)
	{
		thread t1(workThread);
		cout << "������Ҫ��������ݣ�\n";
		string str;
		cin >> str;
		g_cache.push_back(str);
		g_cv.notify_all();
		t1.join();
	}
	//g_cv.notify_all();
	//t1.join();
	cout << "�������" << endl;
    return 0;
}

/*
1������N���ı��ļ�(N>4)��ÿ���ļ���С��5M����ʽ������, ����, �Ա�
�ֱ�ʹ�õ��̺߳Ͷ��̣߳�ͳ��ÿ���ļ���ƽ�����䣬�Ա�����ִ��ʱ���������ַ�����ʱ���١�*/


void writefile(int N)
{
	ofstream outfile;
	for (int i = 0; i < N; i++)
	{
		string filename;
		filename = to_string(i + 1) + ".txt";
		outfile.open(filename);
		outfile << "����," << "�Ա�," << "����" << endl;
		for (int j = 0; j < 3000; ++j)
		{
			outfile << "С��" << j << ",��," << "20" << endl;
		}
		outfile.close();
	}
}
void readfile(string filename)
{
	ifstream infile;
	infile.open(filename);
	string line;
	int rownum = 0;
	double sum = 0;
	double aveg = 0;
	getline(infile, line);
	while (getline(infile, line))
	{
		++rownum;
		smatch math;
		if (regex_search(line, math, regex(".*,(\\d+)")))
		{
			sum = sum + stoi(math[1]);
		}
	}
	aveg = sum / rownum;
	cout << aveg << endl;
	cout << filename << "�����߳����\n";
	infile.close();
}

int main2()
{
	int N = 5;
	writefile(N);
	time_t begin_time = time(nullptr);
	for (int i = 0; i < N; i++)
	{
		string filename;
		filename = to_string(i + 1) + ".txt";
		readfile(filename);
	}
	time_t end_time = time(nullptr);
	time_t sumtime = end_time - begin_time;
	cout << "���߳���ʱ"<<sumtime << endl;

	begin_time = time(nullptr);
	vector<thread*> Threads;
	for (int i=0;i<N;i++)
	{
		string name = i + ".txt";
		thread *p=new thread(readfile, name);
		Threads.push_back(p);
	}
	for (thread *p:Threads)
	{
		p->join();
		delete p;
	}
// 		thread t2(readfile, "2.txt");
// 		thread t3(readfile, "3.txt");
// 		thread t4(readfile, "4.txt");
// 		thread t5(readfile, "5.txt");
// 		t1.join();
// 		t2.join();
// 		t3.join();
// 		t4.join();
// 		t5.join();
	end_time = time(nullptr);
	sumtime = end_time - begin_time;
	cout << "���߳���ʱ" << sumtime << endl;
	return 0;
}
void readfile1()
{
	ifstream infile;
	string line;
	int rownum = 0;
	double sum = 0;
	double aveg = 0;
	getline(infile, line);
	while (getline(infile, line))
	{
		++rownum;
		smatch math;
		if (regex_search(line, math, regex(".*,(\\d+)")))
		{
			sum = sum + stoi(math[1]);
		}
	}
	aveg = sum / rownum;
	cout << aveg << endl;
	cout << "�����߳����\n";
	infile.close();
}

void readfile2()
{
	unique_lock<mutex> lk(g_mutex);
	g_cv.wait(lk);
	ifstream infile;
	string line;
	int rownum = 0;
	double sum = 0;
	double aveg = 0;
	getline(infile, line);
	while (getline(infile, line))
	{
		++rownum;
		smatch math;
		if (regex_search(line, math, regex(".*,(\\d+)")))
		{
			//cout << math[1] << endl;
			sum = sum + stoi(math[1]);
		}
	}
	aveg = sum / rownum;
	cout << aveg << endl;
	cout << "�����߳����\n";
	infile.close();
	/*return aveg;*/
}
int main16()
{
	ifstream infile;
	int N = 6;
	writefile(N);  
	time_t begin_time = time(nullptr);
	for (int i = 0; i < N; i++)
	{
		thread t1(readfile2);
		double average = 0;
		string filename;
		filename = to_string(i + 1) + ".txt";
		infile.open(filename);
		if (infile)
		{
			g_cv.notify_all();
		}
		t1.join();
	}
	time_t end_time = time(nullptr);
	time_t sumtime = end_time - begin_time;
	cout << sumtime << endl;
	return 0;
}



int main15()
{
	int N = 6;
	writefile(N);
	ifstream infile;
	for (int i = 0; i < N; i++)
	{
		string filename;
		filename = to_string(i + 1) + ".txt";
		infile.open(filename);
		if (infile)
		{
			readfile1();
		}

	}
	return 0;
}
int main11()
{
	ifstream infile;
	int N = 6;
	for (int i = 0; i < N; i++)
	{
		string filename;
		filename = to_string(i + 1) + ".txt";
		infile.open(filename);
		string line;
		int rownum = 0;
		double sum = 0;
		double aveg = 0;
		getline(infile, line);
		while (getline(infile, line))
		{
			++rownum;
			smatch math;
			if (regex_search(line, math, regex(".*,(\\d+)")))
			{
				//cout << math[1] << endl;
				sum = sum + stoi(math[1]);
			}
		}
		aveg = sum / rownum;
		cout << aveg << endl;
		infile.close();
	}
	
	return 0;
}
