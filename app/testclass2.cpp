#include "testclass2.h"

TestClass2::TestClass2(QObject *parent)
    : QObject{parent}, value(0)
{
}

void TestClass2::doSomething(int a_value)
{
    value = a_value;
}

