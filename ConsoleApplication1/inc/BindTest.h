#pragma once
#include <string>

// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html

class MyClass {
    public:
    MyClass(int x, std::string y): _x{x},_y{y} {}
    void incrementX() {
        ++_x;
    }
    int getX() const {return _x;}
    void setX(int x){_x = x;}

    static std::string getStringFromInstance(const MyClass& instance) {
        return instance._y;
    }

    private:
    int _x;
    std::string _y;
};


#ifdef __EMSCRIPTEN__

#include <emscripten/bind.h>

using namespace emscripten;

// https://stackoverflow.com/questions/37747205/cmake-project-for-emscripten
EMSCRIPTEN_BINDINGS(ConsoleApplication) {
    class_<MyClass>("MyClass")
        .constructor<int,std::string>()
        .function("incrementX", &MyClass::incrementX)
        .property("x", &MyClass::getX, &MyClass::setX)
        .class_function("getStringFromInstance", &MyClass::getStringFromInstance);
}

#endif