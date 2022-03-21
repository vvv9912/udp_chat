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
public slots:
    void onMessageRecvied(QString message);
private slots:
    void on_Send_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_connect_clicked();
signals:

    void SendClicked(QString text);

    void ConnectClicked(int local_port_, int sent_port_);

    void DisconnectClicked(int i);

private:
    int local_port;
    int sent_port;
    Ui::MainWindow *ui;
    QString nickname;
    QUdpSocket udpSocket;
    int clicked;
};
#endif // MAINWINDOW_H
