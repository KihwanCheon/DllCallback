// Caller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include "DLL_API.h"

typedef ICallback*(*GetInstance_)();
typedef bool (*Destroy_)(ICallback*);

void DoSomething(ICallback& cb);

int main()
{
    HINSTANCE hGetProcIDDLL = LoadLibraryA("Callee");

	if (hGetProcIDDLL == nullptr)
	{
		std::cout << "Loading dll failed" << std::endl;
		return -1;
	}

	GetInstance_ _getInstance =  (GetInstance_)(GetProcAddress(hGetProcIDDLL, "GetInstance"));
	Destroy_ _destroy = (Destroy_)(GetProcAddress(hGetProcIDDLL, "Destroy"));

	ICallback* callback = nullptr;
	
	if (!_getInstance)
	{
		std::cout << "Loading GetInstance function failed" << std::endl;
		return -1;
	}

	if (!_destroy)
	{
		std::cout << "Loading Destroy function failed" << std::endl;
		return -1;
	}
	
	callback = _getInstance();

	DoSomething(*callback);
	
	_destroy(callback);
	
	return 0;
}
