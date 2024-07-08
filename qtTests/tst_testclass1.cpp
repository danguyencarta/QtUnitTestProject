#include "tst_testclass1.h"
#include "testclass1.h"

// add necessary includes here

tst_testClass1::tst_testClass1() {}

tst_testClass1::~tst_testClass1() {}

void tst_testClass1::initTestCase() {}

void tst_testClass1::cleanupTestCase() {}

void tst_testClass1::test_case1() {
    TestClass1 *class1 = new TestClass1();
    int value = 4;
    class1->doSomething(value);
    QCOMPARE(value, class1->getValue());
}

#include "tst_testclass1.moc"
