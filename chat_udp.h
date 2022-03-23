#ifndef CHAT_UDP_H
#define CHAT_UDP_H
#include <QString>
#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QByteArray>

class ChatUdp : public QObject
{
    Q_OBJECT
public:
    ChatUdp();

public slots:
    void disconnect();
    void send(QString message);
    void connect(int srcPort, int destPort);

private slots:
    void readPendingDatagrams();

signals:
    void messageRecived(QString message);

private:
    int _srcPort;
    int _destPort;
    QString _nickname;
    QUdpSocket _udpSocket;
};

#endif // CHAT_UDP_H
