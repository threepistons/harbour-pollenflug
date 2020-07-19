#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include <QQuickView>
#include <QQmlContext>
#include <QGuiApplication>

#include "pollenflug.h"

int main(int argc, char *argv[]) {
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    QQmlContext *context = view.data()->rootContext();
    Pollenflug pollenflug;
    context->setContextProperty("pollenflug", &pollenflug);

    GermanPollenBackend *germanPollenBackend = pollenflug.getGermanPollenBackend();
    context->setContextProperty("germanPollenBackend", germanPollenBackend);

    context->setContextProperty("applicationVersion", QString(VERSION_NUMBER));

    view->setSource(SailfishApp::pathTo("qml/harbour-pollenflug.qml"));
    view->show();
    return app->exec();
}
