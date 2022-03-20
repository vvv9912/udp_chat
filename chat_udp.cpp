#include "chat_udp.h"
#include "mainwindow.h"
Chat_udp::Chat_udp(int _port)
{
    port = _port;
    //repeat = 0;
    if (udpSocket.bind(QHostAddress::LocalHost, port))
    {
        qInfo() << "Started on: "
                << udpSocket.localAddress()
                << ":"
                << udpSocket.localPort();
        connect(&udpSocket,&QUdpSocket::readyRead, this, &Chat_udp::ReadPendingDatagrams);

    }


}

void Chat_udp::ReadPendingDatagrams()
{
    while (udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket.receiveDatagram();
        Readmessage = QString(datagram.data());
       // qInfo() << datagram.data();
        qInfo() << Readmessage;
        //datagram.data()

    }
}

void Chat_udp::Send(QString value)
{
QByteArray data = value.toLatin1();
QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);
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
