#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chat_udp.h>
#include <QString>
#include <QObject>
#include <QByteArray>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Chat_udp chat;
public slots:
    void onMessageRecvied(QString message);
private slots:
    void on_Send_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString nickname;
    QUdpSocket udpSocket;
};
#endif // MAINWINDOW_H
