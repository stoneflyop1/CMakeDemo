#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <TestLib/Asset.h>

namespace TestLib {

	void Asset::AddProperty(std::weak_ptr<RelProperty> relP) {
		relProps_.push_back(relP);
	}

	void Asset::Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
		writer.StartObject();
		writer.String("name");
		writer.String(name_.c_str());
		writer.String("id");
		writer.Int(id_);
		writer.EndObject();
	}

	bool Asset::operator==(const Asset& rhs) const {
		return name_ == rhs.name_ && id_ == rhs.id_;
	}

	bool Asset::operator!=(const Asset& rhs) const {
		return !(operator==(rhs));
	}

	Asset& Asset::operator=(const Asset& rhs) {
		name_ = rhs.name_;
		id_ = rhs.id_;
		return *this;
	}
}

