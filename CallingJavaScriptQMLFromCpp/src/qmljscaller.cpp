#include <QDebug>
#include <QVariant>
#include <QMetaObject>
#include "qmljscaller.hpp"

QmlJsCaller::QmlJsCaller(QObject *parent)
    : QObject{parent} {

}

void QmlJsCaller::cppMethod(const QString &param) {
    qDebug() << "This is C++ talking, calling QML JavaScript function";
    callJSMethod(param);
}

void QmlJsCaller::setQmlRootObject(QObject *ptr) {
    _qmlRootObject = ptr;
}

void QmlJsCaller::callJSMethod(const QString &param) {
    QVariant returnedValue;
    QVariant cppParameter = QVariant::fromValue(param);

    // Calling the javaScript function from C++
    QMetaObject::invokeMethod(_qmlRootObject, "qmlJSFunction"
                              , Q_RETURN_ARG(QVariant, returnedValue)
                              , Q_ARG(QVariant, cppParameter));

    qDebug() << "C++ talking, sone calling QML JavaScript, the return value is: "
             << returnedValue.toString();
}
