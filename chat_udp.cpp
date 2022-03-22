#include "chat_udp.h"

Chat_udp::Chat_udp()
{
    QObject::connect(&udpSocket,&QUdpSocket::readyRead, this, &Chat_udp::ReadPendingDatagrams);


}
void Chat_udp::connectserver()
{
    udpSocket.abort();
    udpSocket.bind(QHostAddress::LocalHost, local_port);

}
void Chat_udp::ReadPendingDatagrams()
{
    while (udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket.receiveDatagram();
        Readmessage = QString::fromUtf8(datagram.data());
        emit messageRecived(Readmessage);
    }
}

void Chat_udp::Send(QString value)
{


    QByteArray data = value.toUtf8();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, sent_port);
    udpSocket.writeDatagram(datagram); //добавить проверку на отправление
}

void Chat_udp::Process(QString value)
{
    QString message;
    nickname = "from "+QString::number(udpSocket.localPort());
    message = nickname + ": " + value;
    Send(message);

}
void Chat_udp::disc()
{
    udpSocket.abort();
}
