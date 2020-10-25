#include "Callback.h"

#include <iostream>
#include <string>
#include <IData.h>

Callback::Callback() = default;

Callback::~Callback() = default;

void Callback::DoSomeThing(IInData* inData, IOutData* outData)
{
	char* buffer = nullptr;
	unsigned len = 0;
	inData->Read(&buffer, &len);
	outData->Write(&buffer, &len);
}

void Callback::DoSomeThingVec(std::vector<char>* inData, std::vector<char>* outData)
{
	char* data = &((*inData)[0]);
	std::string in(data, data + inData->size());
	
	std::string out = "out :: " + in;
	outData->reserve(0);
	std::copy(out.begin(), out.end(), std::back_inserter(*outData));
}

void Callback::DoSomeThingRef(IInData& inData, IOutData& outData)
{
	char* buffer = nullptr;
	unsigned len = 0;
	
	inData.Read(&buffer, &len);
	outData.Write(&buffer, &len);
}

void Callback::DoSomeThingRefVec(std::vector<char>& inData, std::vector<char>& outData)
{
	char* data = &((inData)[0]);

	std::string in(data, data + inData.size());
	
	std::string out = "out :: " + in;
	outData.reserve(0);
	std::copy(out.begin(), out.end(), std::back_inserter(outData));
}
