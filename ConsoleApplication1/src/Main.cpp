// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
    #include <WasmTest.h>
#endif

#include <iostream>
#include <TestLib/Asset.h>
#include <TestLib/Document.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_KEEPALIVE
#endif
int Test() {
    TestLib::Document doc;
    auto a1 = std::make_shared<TestLib::Asset>("nihao");
    auto a2 = std::make_shared<TestLib::Asset>("wohao");
    auto a3 = std::make_shared<TestLib::Asset>("tahao");
    doc.AddAsset(a1);
    doc.AddAsset(a2);
    doc.AddAsset(a3);
    doc.AddAsset("dajiahao");

    auto p1 = std::make_shared<TestLib::Property>("Prop1", 123.0f);
    auto rp1 = std::make_shared<TestLib::RelProperty>("RelProp1", p1);
    rp1->AddAsset(a1);
    rp1->AddAsset(a2);
    rp1->AddAsset(a3);
    a1->AddProperty(rp1);
    a2->AddProperty(rp1);
    a3->AddProperty(rp1);
    doc.AddProperty(rp1);
    return doc.ToJson().length();
}

#ifdef __cplusplus
}
#endif

int main()
{
    
    auto str = Test();

    std::cout << "Hello World!" << str <<std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
