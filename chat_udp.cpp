#include "chat_udp.h"

ChatUdp::ChatUdp()
{
    QObject::connect(&_udpSocket, &QUdpSocket::readyRead, this, &ChatUdp::readPendingDatagrams);
}

void ChatUdp::connect(int srcPort, int destPort)
{
    _srcPort = srcPort;
    _destPort = destPort;
    _udpSocket.abort();
    _udpSocket.bind(QHostAddress::LocalHost, srcPort);
    _udpSocket.connectToHost(QHostAddress::LocalHost, destPort);
}

void ChatUdp::disconnect()
{
    _udpSocket.abort();
    _udpSocket.disconnectFromHost();
}

void ChatUdp::readPendingDatagrams()
{
    QString message;
    while (_udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = _udpSocket.receiveDatagram();
        message += QString::fromUtf8(datagram.data());
    }
    emit messageRecived(message);
}

void ChatUdp::send(QString value)
{
    value = "from "+QString::number(_udpSocket.localPort())+": "+value;
    QByteArray data = value.toUtf8();
    QNetworkDatagram datagram(data, QHostAddress::LocalHost, _destPort);
    _udpSocket.writeDatagram(datagram);
}





