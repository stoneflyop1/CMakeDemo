#pragma once
#include <string>
#include <vector>
#include "BaseEntity.h"
#include "Serde.h"

namespace TestLib {
	class Property : public BaseEntity, public Serde
	{
	public:
		Property(std::string name, double value) :BaseEntity(), name_{ name }, value_{ value }{  }
		Property(const Property& p) :BaseEntity(), name_{ p.name_ }, value_{ p.value_ }{ }
		~Property() = default;
		std::string GetName() const { return name_; }
		double GetValue() const { return value_; }

		// Inherited via Serde
		virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;

	private:
		std::string name_;
		double value_;
	};
}


