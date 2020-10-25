#pragma once
#include "ICallback.h"


#ifdef _DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" // name mangling for LoadLibrary.
{
	DLL_API ICallback* __stdcall GetInstance();

	DLL_API bool __stdcall Destroy(ICallback* callback);
}

DLL_API ICallback* __stdcall GetInstance();

DLL_API bool __stdcall Destroy(ICallback* callback);
