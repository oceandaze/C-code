// 0125.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;
int main1()
{
	cout << boolalpha<<regex_match("2019-08", regex("\\d{4}-\\d{1,2}")) << endl;
    return 0;
}

/*���󣺳������������û������ֻ����룬�ж��Ƿ�����139��ͷ�ĺϷ��ֻ��ţ�
��������У��ͨ��������������У��ʧ�ܣ�Ȼ�����û��������롣 */

int main2()
{
	string line;
	while (cin >> line)
	{
		
		if (regex_match(line,regex("^139\\d{8}")) )
		{
			cout << "��֤ͨ��" << endl;
			break;
		}
		else
		{
			cout << "����������" << endl;
		}

	}
	
	
	return 0;
}

/*���󣺳������������û����������˺ţ��ж��Ƿ�Ϸ������˺ţ�
��������У��ͨ����
����������У��ʧ�ܣ�Ȼ�����û��������롣

eekekkeke@126.com
eekekkeke@qq.com

�û���������1λ�����Գ������֡���ĸ */
int main3()
{
	string line;
	while (cin >> line)
	{

		if (regex_match(line, regex("(\\w+)@(qq|126)\\.com")))
		{
			cout << "��֤ͨ��" << endl;
			break;
		}
		else
		{
			cout << "����������" << endl;
		}

	}


	return 0;
}

/*���󣺳������������û��������֣��ж��Ƿ�Ϸ����֣�
��������У��ͨ����
����������У��ʧ�ܣ�Ȼ�����û��������롣

���֣�123��333.4��
����
	3333.
	0111
	*/

int main4()
{
	string line;
	while (cin >> line)
	{

		if (regex_match(line, regex("(0|[1-9]+\\d*)|^(0|([1-9]+))(\\.\\d+)")))
		{
			cout << "��֤ͨ��" << endl;
			//break;
		}
		else
		{
			cout << "����������" << endl;
		}

	}


	return 0;
}

int main()
{
	string str = "ksdfj2022-01-25dfasj2022-01-26ddkk2022-01-27sadj";
	smatch math;
// 	if (regex_search(str,math,regex("(\\d+)-(\\d+)-(\\d+)"))) //(\\d+-\\d+-\\d+) 
// 	{
// // 		for (size_t i=1;i<math.size();++i)
// // 		{
// // 			cout << math[i] << endl;
// // 		}
// 
// 		cout << "�꣺" << math[1] << endl;
// 		cout << "�£�" << math[2] << endl;
// 		cout << "�գ�" << math[3] << endl;
// 	}
	string::const_iterator iter = str.cbegin();
	while (regex_search(iter,str.cend(), math, regex("(\\d+)-(\\d+)-(\\d+)"))) 
	{
		iter = math[0].second;
		cout << "�꣺" << math[1] << endl;
		cout << "�£�" << math[2] << endl;
		cout << "�գ�" << math[3] << endl;
		cout << "---------------------------" << endl;
	}
	return 0;
}