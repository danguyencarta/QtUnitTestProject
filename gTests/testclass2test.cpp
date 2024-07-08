#include <gtest/gtest.h>
#include "testclass2.h"

namespace {

// The fixture for testing class Foo.
class TestClass2Test : public testing::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    TestClass2Test() {
        // You can do set-up work for each test here.
    }

    ~TestClass2Test() override {
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
TEST_F(TestClass2Test, MethodBarDoesAbc) {
    TestClass2 *class2 = new TestClass2();
    class2->doSomething(4);
}

// Tests that Foo does Xyz.
TEST_F(TestClass2Test, DoesXyz) {
    // Exercises the Xyz feature of Foo.
    ASSERT_EQ(5,5);
}

}
