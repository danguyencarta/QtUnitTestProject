#include "tst_testclass1.h"
#include "tst_testclass2.h"
#include <QtQuickTest/QtQuickTest>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QObject>

// int main(int argc, char *argv[])
// {
//     tst_testClass1 *pTst_testClass1 = new tst_testClass1();
//     tst_testClass2 *pTst_testClass2 = new tst_testClass2();
//     QTest::qExec(pTst_testClass1);
//     QTest::qExec(pTst_testClass2);
//     // QGuiApplication app(argc, argv);
//     // QQmlApplicationEngine engine;
//     // QObject::connect(
//     //     &engine,
//     //     &QQmlApplicationEngine::objectCreationFailed,
//     //     &app,
//     //     []() { QCoreApplication::exit(-1); },
//     //     Qt::QueuedConnection);
//     // engine.loadFromModule("untitled", "Main");
//     // return app.exec();
// }

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:
    void applicationAvailable()
    {
        // Initialization that only requires the QGuiApplication object to be available
        tst_testClass1 *pTst_testClass1 = new tst_testClass1();
        tst_testClass2 *pTst_testClass2 = new tst_testClass2();
        QTest::qExec(pTst_testClass1);
        QTest::qExec(pTst_testClass2);
    }

    void qmlEngineAvailable(QQmlEngine *engine)
    {
        // Initialization requiring the QQmlEngine to be constructed
        engine->rootContext()->setContextProperty("myContextProperty", QVariant(true));
    }

    void cleanupTestCase()
    {
        // Implement custom resource cleanup
    }
};

QUICK_TEST_MAIN_WITH_SETUP(qmlTest, Setup)

#include "tst_main.moc"
// QUICK_TEST_MAIN(qmlTest)


