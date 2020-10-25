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
	ICallback* callback = GetInstance();
	
	if (!callback)
	{
		std::cout << "GetInstance function failed" << std::endl;
		return -1;
	}

	DoSomething(*callback);

	Destroy(callback);

	return 0;
}