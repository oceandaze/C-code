// 0125.cpp : 定义控制台应用程序的入口点。
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

/*需求：程序启动后，请用户输入手机号码，判断是否是以139打头的合法手机号，
如果是输出校验通过，如果不是输出校验失败，然后请用户重新输入。 */

int main2()
{
	string line;
	while (cin >> line)
	{
		
		if (regex_match(line,regex("^139\\d{8}")) )
		{
			cout << "验证通过" << endl;
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}

	}
	
	
	return 0;
}

/*需求：程序启动后，请用户输入邮箱账号，判断是否合法邮箱账号，
如果是输出校验通过，
如果不是输出校验失败，然后请用户重新输入。

eekekkeke@126.com
eekekkeke@qq.com

用户名：最少1位，可以出现数字、字母 */
int main3()
{
	string line;
	while (cin >> line)
	{

		if (regex_match(line, regex("(\\w+)@(qq|126)\\.com")))
		{
			cout << "验证通过" << endl;
			break;
		}
		else
		{
			cout << "请重新输入" << endl;
		}

	}


	return 0;
}

/*需求：程序启动后，请用户输入数字，判断是否合法数字，
如果是输出校验通过，
如果不是输出校验失败，然后请用户重新输入。

数字：123、333.4、
错误：
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
			cout << "验证通过" << endl;
			//break;
		}
		else
		{
			cout << "请重新输入" << endl;
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
// 		cout << "年：" << math[1] << endl;
// 		cout << "月：" << math[2] << endl;
// 		cout << "日：" << math[3] << endl;
// 	}
	string::const_iterator iter = str.cbegin();
	while (regex_search(iter,str.cend(), math, regex("(\\d+)-(\\d+)-(\\d+)"))) 
	{
		iter = math[0].second;
		cout << "年：" << math[1] << endl;
		cout << "月：" << math[2] << endl;
		cout << "日：" << math[3] << endl;
		cout << "---------------------------" << endl;
	}
	return 0;
}