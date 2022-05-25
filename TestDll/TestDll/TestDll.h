#pragma once

#ifdef TESTDLL_EXPORTS  
#define DLL_EXPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT extern "C" __declspec(dllimport)
#endif

DLL_EXPORT	 //”≥…‰πÿœµ
int Add(int a, int b);

DLL_EXPORT
int Minus(int a, int b);
