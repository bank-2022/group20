#include "lukijaengine.h"

QSerialPort *serial;
LukijaEngine::LukijaEngine(QObject *parent)


{

    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    connect(serial,SIGNAL(readyRead()),this,SLOT(recvSerial()));


}

LukijaEngine::~LukijaEngine()
{
    serial->close();
}

int LukijaEngine::returnValueToLukijaDll()
{
    return response;
}

void LukijaEngine::recvSerial()
{

    QByteArray ba = serial->readAll();

    ba = ba.simplified();
    ba = ba.mid(1,10);
    qDebug() <<ba;
    const QString response = QString::fromUtf8(ba);
    emit returnValueToLukijaDll();


}

QString LukijaEngine::getResponse() const
{

}









