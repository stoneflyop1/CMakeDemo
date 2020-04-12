#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include <TestLib/Property.h>

void TestLib::Property::Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const
{
	writer.StartObject();
	writer.String("id");
	writer.Int(id_);
	writer.String("name");
	writer.String(name_.c_str());
	writer.String("value");
	writer.Double(value_);
	writer.EndObject();
}
