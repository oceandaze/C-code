// 0122.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
using namespace std;



int main1()
{
	stack<int> s1;
	s1.push(34);
	s1.push(33);
	s1.push(100);

	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
    return 0;
}



int main3()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(16);
	d1.push_back(0);
	d1.push_front(4);
	cout << "d1[1]=" << d1[1] << endl;
	for (size_t i=0;i<d1.size();++i)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	for (auto iter=d1.begin();iter!=d1.end();++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	for (auto i : d1)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
int getValue(char operation)
{
	int val;
	switch (operation)
	{
	case '+':
		val = 1;
		break;
	case '-':
		val = 1;
		break;
	case '*':
		val = 2;
		break;
	case '/':
		val = 2;
		break;
	default:
		break;
	}
	return val;
}

int main()
{
	//string s="1+((2+3)*4)-5";
	//string s = "1+2*3";
	string s = "1+2*3+(4*5+6)*7";
	cin >> s;
	stack<char> s1;
	queue<char> q1;
	stack<double> res;
	for (auto i:s)
	{
		if (isdigit(i))
		{
			q1.push(i);
		}
		else if(i!='('&& i!=')')
		{
			while (1)
			{
				if (s1.empty() || s1.top() == '(')
				{
					s1.push(i);
					break;
				}
				else if (getValue(i) > getValue(s1.top()))
				{
					s1.push(i);
					break;
				}
				else
				{
					q1.push(s1.top());
					s1.pop();
				}
			}
		}
		else
		{
			if (i=='(')
			{
				s1.push(i);
			}
			else
			{
				while (s1.top()!='(')
				{
					q1.push(s1.top());
					s1.pop();
				}
				s1.pop();
			}
		}
	}
	while (!s1.empty())
	{
		q1.push(s1.top());
		s1.pop();
	}
// 	while (!q1.empty())
// 	{
// 		cout << q1.front();
// 		q1.pop();
// 	}
	while (!q1.empty())
	{
		if (isdigit(q1.front()))
		{
			res.push((q1.front()-48));
		}
		else
		{
			double a= res.top();
			res.pop();
			double b=res.top();
			res.pop();
			if (q1.front()=='+')
			{
				double c = b + a;
				res.push(c);
			}
			if (q1.front() == '-')
			{
				double c = b - a;
				res.push(c);
			}
			if (q1.front() == '*')
			{
				double c = b * a;
				res.push(c);
			}
			if (q1.front() == '/')
			{
				double c = b / a;
				res.push(c);
			}
		}
		q1.pop();
	}
	cout <<s<<"="<< res.top();
	return 0;
}