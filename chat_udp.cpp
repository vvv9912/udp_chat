#include "chat_udp.h"

Chat_udp::Chat_udp()
{

    if (udpSocket.bind(QHostAddress::LocalHost, local_port))
    {

       QObject::connect(&udpSocket,&QUdpSocket::readyRead, this, &Chat_udp::ReadPendingDatagrams);
       /*  qInfo() << "Started on: "
                 << udpSocket.localAddress()
                 << ":"
                 << udpSocket.localPort();*/
    }
    else
    {
        Readmessage = "error";
    }

}

void Chat_udp::ReadPendingDatagrams()
{
    while (udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket.receiveDatagram();
        Readmessage = QString(datagram.data());
       // qInfo() << datagram.data();
        emit messageRecived(Readmessage);
    }
}

void Chat_udp::Send(QString value)
{
QByteArray data = value.toLatin1();
QNetworkDatagram datagram(data, QHostAddress::Broadcast, sent_port);
udpSocket.writeDatagram(datagram); //добавить проверку на отправление

}

void Chat_udp::Process(QString value)
{
    QString message;
    if (nickname.isEmpty())
    {
        nickname = value;
        message = nickname + " is join";
        Send(message);
    }
    else
    {
    message = nickname + ": " + value;
   /* message.append(nickname);
    message.append(": ");
    message.append(value);*/
    Send(message);
    }
}
