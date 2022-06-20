#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "trw.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TRW trw;
    trw.readOfFile();

    QQmlContext* qmlContext = engine.rootContext();
    qmlContext->setContextProperty("trw", &trw);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    trw.slotPrintTotalTasks();

    int forStop = app.exec(); // Я не понял как перехватить сигнал закрывания окна

    trw.writeTasksToFile();

    return forStop;
}
