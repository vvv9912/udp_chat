#include "mainwindow.h"
#include "chat_udp.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int port =2021;
//    Chat_udp chat(port);
/*    QString value = "vladso";
    chat.Process(value);*/
    return a.exec();
}
