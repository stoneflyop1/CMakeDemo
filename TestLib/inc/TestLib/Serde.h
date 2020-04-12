#pragma once
#include <string>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

namespace TestLib {
	class Serde {
	public:
		virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const = 0;
		virtual std::string ToJson() const;
	};
}
