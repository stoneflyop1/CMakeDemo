#pragma once
#include <string>
#include <vector>
#include <memory>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include "Serde.h"
#include "Asset.h"
#include "RelProperty.h"
using namespace std;

namespace TestLib {
    class Document : public Serde {
    public:
        Document() = default;
        ~Document() = default;
        void Serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;
        void AddAsset(shared_ptr<Asset> a);
        void AddAsset(string name);
        vector<shared_ptr<Asset>> GetAssets() const {
            return assets_;
        }
        void AddProperty(shared_ptr<RelProperty> relP);

    private:
        vector<shared_ptr<Asset>> assets_;
        vector<shared_ptr<RelProperty>> relProps_;
    };
}


