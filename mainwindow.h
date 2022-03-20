#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
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
    void Process(QString value);
    void Send(QString value);
    void ReadPendingDatagrams();
private slots:
    void on_Send_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int local_port;
    int sent_port;
    QString nickname;
    QUdpSocket udpSocket;
};
#endif // MAINWINDOW_H
