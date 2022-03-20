#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


QObject::connect(&chat, SIGNAL(messageRecived),this, SLOT(onMessageRecvied));

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
    QString text=ui->lineEdit->text().toUtf8();
    chat.Process(text);
    ui->textEdit->append(QString("you: "+text));
   /*QString text=ui->lineEdit->text().toUtf8();
   Process(text);
    ui->textEdit->append(QString("you: "+text));*/
}


void MainWindow::on_pushButton_clicked()
{   /*int local_port = ui->lineEdit_local->text().toInt();
    int sent_port = ui->lineEdit_ydal->text().toInt();*/
   chat.local_port = ui->lineEdit_local->text().toInt();
   chat.sent_port = ui->lineEdit_ydal->text().toInt();
    //QString text = "you take port:" + QString::number(chat.local_port);
    QString text2 = "you take nickname:";
    ui->textEdit->append(QString(text2));
    /* QString text = "you take port:" + QString::number(local_port);
     QString text2 = "you take nickname:";
     ui->textEdit->append(QString(text2));*/

}


