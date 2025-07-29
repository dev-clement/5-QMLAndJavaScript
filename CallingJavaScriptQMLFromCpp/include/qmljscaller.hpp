#ifndef QMLJSCALLER_HPP
#define QMLJSCALLER_HPP

#include <QObject>
#include <QString>

class QmlJsCaller : public QObject
{
    Q_OBJECT
public:
    explicit QmlJsCaller(QObject *parent = nullptr);
    Q_INVOKABLE void cppMethod(const QString &param);
    void setQmlRootObject(QObject *ptr);
private:
    void callJSMethod(const QString &param);
private:
    QObject *_qmlRootObject;
};

#endif // QMLJSCALLER_HPP
