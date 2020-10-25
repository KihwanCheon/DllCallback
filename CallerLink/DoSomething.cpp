
#include <iostream>

#include "ICallback.h"
#include "InOutData.h"

using namespace std;

void DoSomething(ICallback& cb)
{
	{
		InData in;
		OutData out;
		in.Write("hihi");

		cb.DoSomeThing(&in, &out);
		
		string outStr;
		out.Read(outStr);
		cout << outStr << endl;
	}

	{
		std::vector<char> in = { 'H', 'e', 'l', 'l', 'o'};
		std::vector<char> out;
		
		cb.DoSomeThingVec(&in, &out);

		string outStr(out.data(), out.data() + out.size());
		cout << outStr << endl;
	}

	{
		InData in;
		OutData out;
		in.Write("hihi");
		cb.DoSomeThingRef(in, out);

		string outStr;
		out.Read(outStr);
		cout << outStr << endl;
	}

	{
		std::vector<char> in = { 'H', 'e', 'l', 'l', 'o' };
		std::vector<char> out;

		cb.DoSomeThingRefVec(in, out);

		string outStr(out.data(), out.data() + out.size());
		cout << outStr << endl;
	}
}
