#pragma once

#include <vector>

class IInData
{
public:
	virtual ~IInData() = default;
	virtual void Read(char** buffer, unsigned* len) = 0;
};

class IOutData
{
public:
	virtual ~IOutData() = default;
	virtual void Write(char** buffer, const unsigned* len) = 0;
};
