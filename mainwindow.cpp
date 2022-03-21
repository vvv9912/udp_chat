#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//QObject::connect(&chat, &Chat_udp::messageRecived,this, &MainWindow::onMessageRecvied);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMessageRecvied(QString message)
{
 ui->textEdit->append(message);

}

void MainWindow::on_Send_clicked()
{
    QString text=QString::fromUtf8(ui->lineEdit->text().toUtf8());
    ui->textEdit->append(QString("you: "+text));
    emit SendClicked(text);

}



void MainWindow::on_pushButton_disconnect_clicked()
{ //либо как то по другому отключение работает, !чекнуть документацию!
   // chat.local_port = 0;
   // chat.sent_port = 0;
   clicked = 1;
   emit DisconnectClicked(clicked);
   clicked = 0;
}


void MainWindow::on_pushButton_connect_clicked()
{
      local_port = ui->lineEdit_local->text().toInt();
      sent_port = ui->lineEdit_ydal->text().toInt();
      QString text2 = "you take nickname:";
      ui->textEdit->append(QString(text2));

      emit ConnectClicked(local_port,sent_port);
       /* QString text = "you take port:" + QString::number(local_port);
        QString text2 = "you take nickname:";
        ui->textEdit->append(QString(text2));*/
}

