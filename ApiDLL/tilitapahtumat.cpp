#include "tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QObject * parent) : QObject(parent)
{

}

tilitapahtumat::~tilitapahtumat()
{

}

void tilitapahtumat::getTilitapahtumatDB()
{
    qDebug()<<"RESTAPI DLL Engine = Get tili from database";
    QString site_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    dbManager = new QNetworkAccessManager(this);
    connect(dbManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(recvTilitapahtumatFromDB(QNetworkReply*)));
    reply = dbManager->get(request);
}

void tilitapahtumat::recvTilitapahtumatFromDB(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString RaTilitapahtumat;
    int limit = 0;
    foreach (const QJsonValue &value, json_array) {
        if (limit < 10){
        QJsonObject json_obj = value.toObject();
        RaTilitapahtumat+=QString::number(json_obj["id_tilitapahtumat"].toInt())+","+json_obj["paivays"].toInt()
                +","+json_obj["tapahtuma"].toString()+","+json_obj["summa"].toDouble()
                +","+json_obj["id_tili"].toInt()+","+json_obj["id_kortti"].toInt()+"\r";
        limit ++;
        } else {
            emit sendTilitapahtumatToMain(RaTilitapahtumat);
            break;
        }
    }

    qDebug()<<RaTilitapahtumat;

    //emit sendTilitapahtumatToMain(RaTilitapahtumat);

    reply->deleteLater();
    dbManager->deleteLater();
}

