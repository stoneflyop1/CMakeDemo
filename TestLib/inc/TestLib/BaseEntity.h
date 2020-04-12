#pragma once
namespace TestLib {
	class BaseEntity
	{	
	public:
		int GetId() const {
			return id_;
		}
	protected:
		BaseEntity();
		~BaseEntity() = default;
		int id_;
	};
}

