#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <TestLib/Serde.h>

namespace TestLib {
	std::string Serde::ToJson() const {
		rapidjson::StringBuffer sb;
		rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
		Serialize(writer);
		return sb.GetString();
	}
}