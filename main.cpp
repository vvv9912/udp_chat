#include "mainwindow.h"
#include "chat_udp.h"
#include "core.h"
#include <QApplication>
#include <QDebug>
#include <QObject>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    core c;
    return a.exec();
}
