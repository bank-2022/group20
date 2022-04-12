#include "lukijadll.h"

LukijaDll::LukijaDll(QObject *parent) : QObject(parent)
{
    qDebug()<<"At DLL LukijaDll constructor!";
    pLukijaEngine = new LukijaEngine(this);
    connect(pLukijaEngine,SIGNAL(sendValueToLukijaDll(short)),
    this,SLOT(recvValueFromLukijaEngine(short)));
}

LukijaDll::~LukijaDll()
{
    disconnect(pLukijaEngine,SIGNAL(sendValueToLukijaDll(short)),
    this,SLOT(recvValueFromLukijaEngine(char)));
    delete pLukijaEngine;
    pLukijaEngine = nullptr;
}

void LukijaDll::recvSerial()
{
    pLukijaEngine->response;
}

void LukijaDll::recvValueCommand()
{
    pLukijaEngine->response();
}

void LukijaDll::recvValueFromEngine(char response)
{
    emit sendDataToExe(response);
}
