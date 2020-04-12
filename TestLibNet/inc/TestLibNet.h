#pragma once

#include <TestLib/Asset.h>
#include <TestLib/Document.h>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

namespace TestLibNet {
	public ref class Entry
	{
		// TODO: Add your methods for this class here.
	public:
		Entry() { _doc = new TestLib::Document(); }
		~Entry() {
			delete _doc;
		}
		void Add(String^ name);
		String^ GetJson();
		List<String^>^ GetAssets();
	private:
		TestLib::Document* _doc;
	};
}
