#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QRect>

#include "backend.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    Backend blue;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/ApplicationFrontEnd/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("back", &blue);

    return app.exec();
}
