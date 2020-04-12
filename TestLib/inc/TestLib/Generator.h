#pragma once
namespace TestLib {
	class Generator
	{
	public:
		static int NextId() {
			return ++id0_;
		}
	private:
		static int id0_;
	};
	
}


