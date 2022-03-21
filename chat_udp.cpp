#include "chat_udp.h"

Chat_udp::Chat_udp()
{
    QObject::connect(&udpSocket,&QUdpSocket::readyRead, this, &Chat_udp::ReadPendingDatagrams);


}
void Chat_udp::connectserver()
{
    udpSocket.abort();
    udpSocket.bind(QHostAddress::LocalHost, local_port);
    qDebug()<<udpSocket.localPort();
    qDebug()<<udpSocket.peerPort();
    //qDebug()<<local_port;
    qDebug()<<QString(udpSocket.localPort());
    int a = udpSocket.localPort();
    qDebug()<< "port:"<<a;
}
void Chat_udp::ReadPendingDatagrams()
{
    while (udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket.receiveDatagram();
        Readmessage = QString(datagram.data());
        emit messageRecived(Readmessage);
    }
}

void Chat_udp::Send(QString value)
{

    QByteArray data = value.toLatin1();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, sent_port);
    udpSocket.writeDatagram(datagram); //добавить проверку на отправление
    qDebug()<<datagram.destinationAddress();
    qDebug()<<datagram.destinationPort();

}

void Chat_udp::Process(QString value)
{
    QString message;
   /* if (nickname.isEmpty())
    {
        nickname = value;
        message = nickname + " is join";
        Send(message);
    }*/
    //else
    //{
        nickname = "from "+QString::number(udpSocket.localPort());
        message = nickname + ": " + value;
        Send(message);
    //}
}
void Chat_udp::disc()
{
    udpSocket.abort();
}
