#include <iostream>
#include <bits/stdc++.h>
#include "SmartUniquePointer.h"

class MyClass
{
    std::string val1;
    int val2;
    double val3;
    public:
    MyClass(std::string x, int y, double z):
    val1{x}, val2{y}, val3{z}
    {}

    std::string GetVal()
    {
        return val1;
    }

    int GetIntVal()
    {
        return val2;
    }

    double GetDoubleVal()
    {
        return val3;
    }
};

int main()
{
    std::string str = "akin";
    int x = 4;
    double d = 4.5;
    SmartUniquePointer<MyClass> ptr = make_unique_pointer<MyClass>(str, x, d);
}
