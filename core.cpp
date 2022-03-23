#include "core.h"

Core::Core(QObject *parent) : QObject(parent),
    window(new MainWindow()),
    chat(new ChatUdp()),
    chatThread(new QThread())
{
    chat->moveToThread(chatThread);
    connect(chatThread, &QThread::finished, chat, &QObject::deleteLater);

    connect(chat, &ChatUdp::messageRecived, window, &MainWindow::onMessageRecvied);
    connect(window, &MainWindow::sendClicked, chat, &ChatUdp::send);
    connect(window, &MainWindow::connectClicked, chat, &ChatUdp::connect);
    connect(window, &MainWindow::disconnectClicked, chat, &ChatUdp::disconnect);

    chatThread->start();
    window->show();
}

Core::~Core()
{
    chatThread->quit();
    chatThread->wait();
}

