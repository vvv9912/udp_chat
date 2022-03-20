#ifndef CHAT_UDP_H
#define CHAT_UDP_H
#include <QString>
#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QByteArray>
class Chat_udp : public QObject
{

public:
    Chat_udp(int _port);
    QString Readmessage;
    int repeat = 0; //if 1 - errro

public slots:
    void Process(QString value);
    void Send(QString value);
    void ReadPendingDatagrams();


private:
    int port;
    QString nickname;
    QUdpSocket udpSocket;
};

#endif // CHAT_UDP_H
