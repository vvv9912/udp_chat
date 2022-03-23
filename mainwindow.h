#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chat_udp.h>
#include <QString>
#include <QObject>
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
    void onSendClicked();
    void onConnectClicked();

signals:
    void sendClicked(QString text);
    void connectClicked(int local_port_, int sent_port_);
    void disconnectClicked();

private:
    int _localPort;
    int _sentPort;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
