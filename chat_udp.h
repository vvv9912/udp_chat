#ifndef CHAT_UDP_H
#define CHAT_UDP_H
#include <QString>
#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QByteArray>

class Chat_udp : public QObject
{
    Q_OBJECT
public:
    Chat_udp();
    QString Readmessage;
     void connectserver();
     QString q;
     int k;
    int local_port;
    int sent_port;

public slots:
    void Process(QString value);
    void Send(QString value);
    void ReadPendingDatagrams();
signals:
   void messageRecived(QString message);

private:
  //  int port;
    QString nickname;
    QUdpSocket udpSocket;

};

#endif // CHAT_UDP_H
