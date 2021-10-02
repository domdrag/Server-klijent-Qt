#ifndef CLIENT_H
#define CLIENT_H

#include <QByteArray>
#include <QString>
#include <QTcpSocket>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
public slots:
    void onConnectPushed();
    void onConnected();
    void onDisconnected();
    void onErrorOccured();
    void onReadyRead();
    void onReturnPressed();
    void onDisconnectPushed();
private:
    const char ETB = 23;
    Ui::Client* ui;
    QTcpSocket* m_socket;
    QByteArray m_data;

};
#endif // CLIENT_H
