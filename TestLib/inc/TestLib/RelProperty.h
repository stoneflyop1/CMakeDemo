#pragma once
#include <string>
#include <vector>
#include <memory>
#include <rapidjson/writer.h>
#include "BaseEntity.h"
#include "Serde.h"
#include "Property.h"
#include "Asset.h"

namespace TestLib {
	class Asset;
	class RelProperty : public BaseEntity, public Serde
	{
	public:
		RelProperty(std::string name, std::shared_ptr<Property> relating) 
			: BaseEntity(), name_{ name }, relating_{ relating }{}
		~RelProperty() = default;
		void AddAsset(std::shared_ptr<Asset> p);
		void AddAsset(std::string name);
		std::vector<std::shared_ptr<Asset>> GetProperties() const {
			return related_;
		}
		void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;
	private:
		std::string name_;
		std::shared_ptr<Property> relating_;
		std::vector<std::shared_ptr<Asset>> related_;
	};
}

