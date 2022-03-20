#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}
void MainWindow::ReadPendingDatagrams()
{
    while (udpSocket.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = udpSocket.receiveDatagram();
        // QString(datagram.data()); //in qstrig
       // qInfo() << datagram.data();;
        ui->textEdit->append(QString(datagram.data()));
        //datagram.data()

    }
}

void MainWindow::Send(QString value)
{
QByteArray data = value.toLatin1();
QNetworkDatagram datagram(data, QHostAddress::Broadcast, sent_port);
udpSocket.writeDatagram(datagram); //добавить проверку на отправление

}

void MainWindow::Process(QString value)
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
    Send(message);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Send_clicked()
{
   Process(ui->lineEdit->text().toUtf8());
}


void MainWindow::on_pushButton_clicked()
{
    local_port = ui->lineEdit_local->text().toInt();
    sent_port = ui->lineEdit_ydal->text().toInt();
    QString text = "you take port:" + QString::number(local_port);

    if (udpSocket.bind(QHostAddress::LocalHost, local_port))
    {

        ui->textEdit->append(QString(text));
      /*  qInfo() <<
                << udpSocket.localAddress()
                << ":"
                << udpSocket.localPort();*/
        connect(&udpSocket,&QUdpSocket::readyRead, this, &MainWindow::ReadPendingDatagrams);
     QString text2 = "you take nickname:";
     ui->textEdit->append(QString(text2));
    }
}

