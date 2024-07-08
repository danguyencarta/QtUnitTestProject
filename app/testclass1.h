#ifndef TESTCLASS1_H
#define TESTCLASS1_H

#include <QObject>

class TestClass1 : public QObject
{
    Q_OBJECT
public:
    explicit TestClass1(QObject *parent = nullptr);
    void doSomething(int a_value);
    inline int getValue() {return value;}
private:
    int value;
};

#endif // TESTCLASS1_H
