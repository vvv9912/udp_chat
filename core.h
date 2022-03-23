#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "chat_udp.h"
#include "mainwindow.h"
#include "QThread"

class Core : public QObject
{
    Q_OBJECT

public:
    explicit Core(QObject *parent = nullptr);
    ~Core();

private:
    MainWindow *window;
    ChatUdp *chat;
    QThread *chatThread;
};

#endif // CORE_H
