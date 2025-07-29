#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qmljscaller.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlJsCaller caller;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("QmlJsCaller", &caller);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("JavaScriptQML", "Main");

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    auto rootObjects = engine.rootObjects().at(0);
    caller.setQmlRootObject(rootObjects);

    return app.exec();
}
