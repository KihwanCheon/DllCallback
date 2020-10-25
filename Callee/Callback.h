#pragma once

#include "ICallback.h"

class Callback : public ICallback
{
public:
	Callback();
	virtual ~Callback() override;

	void DoSomeThing(IInData* inData, IOutData* outData) override;
	void DoSomeThingVec(std::vector<char>* inData, std::vector<char>* outData) override;
	void DoSomeThingRef(IInData& inData, IOutData& outData) override;
	void DoSomeThingRefVec(std::vector<char>& inData, std::vector<char>& outData) override;
};

