#pragma once

#include <IData.h>
#include <string>
#include <vector>

class InData : public IInData
{
public:
	InData();
	virtual ~InData() override;

	void Read(char** buffer, unsigned* len) override;

	void Write(const std::string& in);
	
private:
	std::vector<char> data;
};

class OutData : public IOutData
{
public:
	OutData();
	virtual ~OutData() override;

	void Read(std::string& out) ;

	void Write(char** buffer, const unsigned* len) override;

private:
	std::vector<char> data;
};

