// test01241.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Calculator.h"

int main()
{
	Calculator calc;
	string line = "4**4";
#ifdef _DEBUG
	calc.run(line);
#else
	while (getline(cin, line))
	{
		if (line == "quit") {
			break;
		}

		calc.run(line);
	}
#endif
    return 0;
}

