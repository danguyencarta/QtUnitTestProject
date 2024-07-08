#include "tst_testclass2.h"
#include "testclass2.h"

tst_testClass2::tst_testClass2() {}

tst_testClass2::~tst_testClass2() {}

void tst_testClass2::initTestCase() {}

void tst_testClass2::cleanupTestCase() {}

void tst_testClass2::test_case1() {
    TestClass2 *class2 = new TestClass2();
    class2->doSomething(4);
}

#include "tst_testclass2.moc"
