#ifndef LUKIJAENGINE_H
#define LUKIJAENGINE_H

#include <QObject>
#include <QtSerialPort>
#include <QByteArray>
#include <QDebug>

class LukijaEngine : public QObject
{
    Q_OBJECT

public:
    LukijaEngine(QObject *parent = nullptr);
    ~LukijaEngine();
    QString returnValueToLukijaDll();
    void recvSerial();


    const QString &getDataAsString() const;
    void setDataAsString(const QString &newDataAsString);

    QString getResponse() const;
    void setResponse(char newResponse);
    QByteArray ba;
    QString response;
private:
    QByteArray data;




 signals:
    void sendValueToLukijaDll(QString response);
    void readyRead();
};

#endif // LUKIJAENGINE_H
