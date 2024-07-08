#include "testclass1.h"

TestClass1::TestClass1(QObject *parent)
    : QObject{parent}, value(0)
{
}

void TestClass1::doSomething(int a_value)
{
    value = a_value;
}
