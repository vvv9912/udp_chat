#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    std::setlocale(LC_ALL,"Russian");
    ui->setupUi(this);
    connect(ui->_sendBtn, &QPushButton::clicked, this, &MainWindow::onSendClicked);
    connect(ui->_connectBtn, &QPushButton::clicked, this, &MainWindow::onConnectClicked);

    connect(ui->_disconnectBtn, &QPushButton::clicked, this, &MainWindow::disconnectClicked);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMessageRecvied(QString message)
{
    ui->textEdit->append(message);
}

void MainWindow::onSendClicked()
{
    QString text(ui->lineEdit->text().toUtf8());
    ui->textEdit->append(QString("you: "+text));
    emit sendClicked(text);
    ui->lineEdit->clear();
}

void MainWindow::onConnectClicked()
{
    _localPort = ui->lineEdit_local->text().toInt();
    _sentPort = ui->lineEdit_ydal->text().toInt();
    emit connectClicked(_localPort,_sentPort);
}


