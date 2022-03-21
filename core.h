#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "chat_udp.h"
#include "mainwindow.h"
class core : public QObject
{
    Q_OBJECT
public:
    explicit core(QObject *parent = nullptr);
        Chat_udp chat;
        MainWindow w;

public slots:
       void onSendClicked(QString text);
       void onConnectClicked(int local_port_, int sent_port_);
       void onDisconnectClicked(int i);
signals:

};

#endif // CORE_H
