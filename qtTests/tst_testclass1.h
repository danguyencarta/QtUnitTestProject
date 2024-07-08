#ifndef TST_TESTCLASS1_H
#define TST_TESTCLASS1_H

#include <QtTest>

class tst_testClass1 : public QObject
{
    Q_OBJECT
public:
    tst_testClass1();
    ~tst_testClass1();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

#endif // TST_TESTCLASS1_H
