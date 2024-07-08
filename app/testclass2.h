#ifndef TESTCLASS2_H
#define TESTCLASS2_H

#include <QObject>

class TestClass2: public QObject
{
    Q_OBJECT
public:
    explicit TestClass2(QObject *parent = nullptr);
    void doSomething(int a_value);
private:
    int value;
};

#endif // TESTCLASS2_H
