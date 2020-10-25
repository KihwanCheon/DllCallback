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
	virtual void DoSomeThingVec(std::vector<__int8>* inData, std::vector<__int8>* outData) = 0;

	virtual void DoSomeThingRef(IInData& inData, IOutData& outData) = 0;
	virtual void DoSomeThingRefVec(std::vector<__int8>& inData, std::vector<__int8>& outData) = 0;
};