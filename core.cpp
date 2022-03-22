#include "core.h"

core::core(QObject *parent) : QObject(parent)
{

    chat->moveToThread(&chatthread);

    connect(&chatthread, &QThread::started, chat,&Chat_udp::connectserver);
    w.show();
    connect(chat, &Chat_udp::messageRecived,&w, &MainWindow::onMessageRecvied);
    connect(&w, &MainWindow::SendClicked, this, &core::onSendClicked);
    connect(&w, &MainWindow::ConnectClicked, this, &core::onConnectClicked);
    connect(&w, &MainWindow::DisconnectClicked, this, &core::onDisconnectClicked);
    connect(&w, &MainWindow::DisconnectClicked, &chatthread, &QThread::terminate);

}

void core::onSendClicked(QString text)
{
    chat->Process(text);
}
void core::onConnectClicked(int local_port_, int sent_port_)
{
    chat->local_port = local_port_;
    chat->sent_port = sent_port_;
    chatthread.start();
   // chat->connectserver();

}
void core::onDisconnectClicked(int i)
{
    //chatthread.quit();
   // chatthread.wait();
    chat->disc();
   // thread->quit();
    //thread->finished();
}
