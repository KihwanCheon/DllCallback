
#include "InOutData.h"

InData::InData() = default;

InData::~InData()
{
	data.clear();
}

void InData::Read(char** buffer, unsigned* len)
{
	*buffer = data.data();
	*len = static_cast<unsigned>(data.size());
}

void InData::Write(const std::string& in)
{
	data.reserve(0);
	std::copy(in.c_str(), in.c_str() + in.size(), std::back_inserter(data));
}

OutData::OutData() = default;

OutData::~OutData()
{
	data.clear();
}

void OutData::Read(std::string& out)
{
	out.reserve(0);
	std::copy(data.data(), data.data() + data.size(), std::back_inserter(out));
}

void OutData::Write(char** buffer, const unsigned* len)
{
	data.reserve(0);
	std::copy(*buffer, *buffer + *len, std::back_inserter(data));
}
