#pragma once

#include <vector>

class IInData;
class IOutData;

class ICallback
{
public:
	virtual ~ICallback() = default;

public:
	virtual void DoSomeThing(IInData* inData, IOutData* outData) = 0;
	virtual void DoSomeThingVec(std::vector<char>* inData, std::vector<char>* outData) = 0;

	virtual void DoSomeThingRef(IInData& inData, IOutData& outData) = 0;
	virtual void DoSomeThingRefVec(std::vector<char>& inData, std::vector<char>& outData) = 0;
};