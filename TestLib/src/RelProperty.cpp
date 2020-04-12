#include <string>
#include <memory>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <TestLib/RelProperty.h>

namespace TestLib {
	void RelProperty::AddAsset(std::string name) {
		auto p = std::make_shared<Asset>(name);
		AddAsset(p);
	}
	void RelProperty::AddAsset(std::shared_ptr<Asset> p) {
		related_.push_back(p);
	}
	void RelProperty::Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
		writer.StartObject();
		writer.String("id");
		writer.Int(id_);
		writer.String("name");
		writer.String(name_.c_str());
		writer.String("relating");
		writer.Int(relating_->GetId());
		writer.String("related");
		writer.StartArray();
		for (auto p : related_) {
			p->Serialize(writer);
		}
		writer.EndArray();
		writer.EndObject();
	}
}