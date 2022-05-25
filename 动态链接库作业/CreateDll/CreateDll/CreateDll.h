#pragma once

#ifdef CREATEDLL_EXPORTS
#define DLL_EXPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT extern "C" __declspec(dllimport)
#endif

DLL_EXPORT
const char *getVersion();

DLL_EXPORT
int Add(int a, int b);

DLL_EXPORT
void getTime(char *&buffer);