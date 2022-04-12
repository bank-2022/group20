#ifndef LUKIJADLL_H
#define LUKIJADLL_H

#include "LukijaDll_global.h"
#include "lukijaengine.h"

class LUKIJADLL_EXPORT LukijaDll : public QObject
{
    Q_OBJECT

public:

    LukijaDll(QObject *parent = nullptr);
    ~LukijaDll();
    void recvSerial();

signals:
        void sendNumberToExe(QString);
public slots:
        void recvValueCommand();
        void recvValueFromEngine();
private:
        LukijaEngine * pLukijaEngine;
};

#endif // LUKIJADLL_H
