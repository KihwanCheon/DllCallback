

#include "Callback.h"
#include "DLL_API.h"

DLL_API ICallback* __stdcall GetInstance() {
	return new Callback;
}

DLL_API bool __stdcall Destroy(ICallback * callback) {
	Callback* cb = dynamic_cast<Callback*>(callback);
	if (cb)
	{
		delete cb;
		return true;
	}

	return false;
}
