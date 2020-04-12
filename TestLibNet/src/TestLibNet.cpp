#include "pch.h"
#include <string>
#include <memory>

#include <TestLib/Asset.h>
#include <TestLib/Document.h>

#include "TestLibNet.h"

using namespace System::Collections::Generic;

// https://docs.microsoft.com/en-us/cpp/dotnet/how-to-convert-system-string-to-standard-string?view=vs-2019
void MarshalString(String^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace TestLibNet {
	void Entry::Add(String^ name) {
		string os;
		MarshalString(name, os);
		auto a = std::make_shared<TestLib::Asset>(os);
		_doc->AddAsset(a);
	}
	String^ Entry::GetJson() {
		string val = _doc->ToJson();
		return gcnew String(val.c_str());
	}
	List<String^>^ Entry::GetAssets() {
		auto assets = _doc->GetAssets();
		List<String^>^ list = gcnew List<String^>;
		for (auto a : assets) {
			list->Add(gcnew String(a->ToJson().c_str()));
		}
		return list;
	}
}