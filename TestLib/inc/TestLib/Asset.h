#pragma once
#include <string>
#include <rapidjson/writer.h>
#include "Serde.h"
#include "BaseEntity.h"
#include "RelProperty.h"

using namespace std;
namespace TestLib {
	class RelProperty;
	class Asset : public BaseEntity, public Serde
	{
	public:
		Asset(const string& name) : name_{ name } {  }
		Asset(const Asset& rhs) : name_{ rhs.name_ } {}
		//Asset(Asset&& rhs) noexcept :name_{ std::move(rhs.name_) }, id_{ rhs.id_ }{}
		virtual ~Asset() = default;
		void AddProperty(std::weak_ptr<RelProperty> relP);

		void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;

		Asset& operator=(const Asset& rhs);
		bool operator==(const Asset& rhs) const;
		bool operator!=(const Asset& rhs) const;
	private:
		string name_;
		std::vector<std::weak_ptr<RelProperty>> relProps_;
	};
}


