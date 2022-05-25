// test01241.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Calculator.h"

int main()
{
	Calculator calc;
	string line = "(4**2+10)/(9-7)";
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

