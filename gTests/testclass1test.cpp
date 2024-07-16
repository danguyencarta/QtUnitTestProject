//#include "test.h"
#include "testclass1.h"
#include <gtest/gtest.h>

namespace {
class TestClass1Test : public testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    TestClass1Test() {
        // You can do set-up work for each test here.
    }

    ~TestClass1Test() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Class members declared here can be used by all tests in the test suite
    // for Foo.
};


// Tests that the Foo::Bar() method does Abc.
TEST_F(TestClass1Test, TestCase1) {
    TestClass1 *class1 = new TestClass1();
    int value = 4;
    class1->doSomething(value);
    ASSERT_EQ(value+1, class1->getValue());
}

TEST_F(TestClass1Test, DoesXyz) {
    // Exercises the Xyz feature of Foo.
    ASSERT_EQ(5,5);
}
}

// Tests that Foo does Xyz.



