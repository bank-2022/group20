#ifndef RESTAPI_DLLV2_H
#define RESTAPI_DLLV2_H

#include "ApiDLL_global.h"
#include <QDebug>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "tili_asiakas.h"
#include "kortti.h"
#include "asiakas.h"
#include "tilitapahtumat.h"
#include "login.h"

class APIDLL_EXPORT ApiDLL : public QObject
{
    Q_OBJECT
public:
    ApiDLL(QObject *parent);
    ~ApiDLL();
    void Login(QString pin, QString korttinumero);
    void Asiakas(QByteArray kayttisToken, int asiakasId);
    void Tili(QByteArray kayttisToken, int korttiId);
    void Tilitapahtumat(QByteArray kayttisToken, int NostoTiliId);

    void addTilitapahtumat(QByteArray nostoToken, int idtilitapahtumat, QString paivays, QString tapahtuma, int idkortti, double summa, int idtili);
    void UpdateTili(QByteArray kayttisToken, float saldo, int tiliId);


    QByteArray getTokenFromApi();
    QByteArray token;

    const QByteArray &getToken() const;

    int asiakasId;

private:
    QNetworkAccessManager *dbManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString pin;
    QString korttinumero;

    QNetworkAccessManager *asiakasManager;
    QNetworkReply *asiakasreply;
    QByteArray asiakasresponse_data;

    QNetworkAccessManager *tiliManager;
    QNetworkReply *tilireply;
    QByteArray tiliresponse_data;

    QNetworkAccessManager *postManager;
    QNetworkReply *postreply;
    QByteArray postresponse_data;

    QNetworkAccessManager *putManager;
    QNetworkReply *putreply;
    QByteArray putresponse_data;


    tili_asiakas * pTili_Asiakas;
    asiakas * pAsiakas;
    kortti * pKortti;
    tilitapahtumat * pTilitapahtumat;
    login * pLogin;


signals:
    void sendToExe(QString);

    void sendTokenToExe(QByteArray);
    void sendAsiakasToExe(QString);
    void sendTiliToExe(QString, QString, QString);
    void sendTilitapahtumatToExe(QString);
    void addTtilitapahtumatToExe(QString);

    void QuitEventLoop();

public slots:

    void recvTiliSlot(QNetworkReply *reply);
    void recvLoginSlot(QNetworkReply *reply);
    void recvAsiakasSlot(QNetworkReply *reply);
    void recvTilitapahtumatSlot(QNetworkReply *reply);
    void addTilitapahtumatSlot(QNetworkReply *postreply);
    void updateTiliSlot(QNetworkReply *reply);

};

#endif // RESTAPI_DLLV2_H
