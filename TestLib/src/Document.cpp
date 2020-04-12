#include <string>
#include <vector>
#include <memory>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <TestLib/Document.h>

using namespace std;

namespace TestLib {
	void Document::Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
		writer.StartObject();
		writer.String("assets");
		writer.StartArray();
		for (auto a : assets_) {
			a->Serialize(writer);
		}
		writer.EndArray();
		writer.String("properties");
		writer.StartArray();
		for (auto p : relProps_) {
			p->Serialize(writer);
		}
		writer.EndArray();
		writer.EndObject();
	}

	void Document::AddAsset(shared_ptr<Asset> a) {
		assets_.push_back(a);
	}

	void Document::AddAsset(string name) {
		auto a = make_shared<Asset>(name);
		assets_.push_back(a);
	}

	void Document::AddProperty(shared_ptr<RelProperty> relP) {
		relProps_.push_back(relP);
	}
}


