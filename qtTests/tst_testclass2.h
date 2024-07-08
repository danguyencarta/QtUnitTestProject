#ifndef TST_TESTCLASS2_H
#define TST_TESTCLASS2_H

#include <QObject>

class tst_testClass2: public QObject
{
    Q_OBJECT
public:
    tst_testClass2();
    ~tst_testClass2();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

#endif // TST_TESTCLASS2_H
