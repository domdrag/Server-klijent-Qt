#include "client.h"
#include "ui_client.h"

#include <QHostAddress>
#include <QMessageBox>

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client), m_socket(new QTcpSocket(this))
{
    ui->setupUi(this);
    connect(ui->connectPushButton, &QPushButton::clicked, this, &Client::onConnectPushed);
    connect(ui->disconnectPushButton, &QPushButton::clicked, this, &Client::onDisconnectPushed);

    connect(m_socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &Client::onDisconnected);
    connect(m_socket, &QTcpSocket::errorOccurred, this, &Client::onErrorOccured);
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);

    connect(ui->textLineEdit, &QLineEdit::returnPressed, this, &Client::onReturnPressed);
}

Client::~Client()
{
    delete ui;
}

void Client::onConnectPushed()
{
    if(m_socket->state() != QAbstractSocket::ConnectedState)
    {
        ui->connectPushButton->setEnabled(false);
        ui->log->append("Connecting ....");

        QHostAddress server_address(ui->addressLineEdit->text());
        quint16 port(ui->portSpinBox->text().toUInt());
        m_socket->connectToHost(server_address, port);

    }
}

void Client::onConnected()
{
    ui->log->append("Connected.");
    ui->disconnectPushButton->setEnabled(true);
}

void Client::onDisconnected()
{
    ui->log->append("Disconnected by server.");
    ui->connectPushButton->setEnabled(true);
    ui->disconnectPushButton->setEnabled(false);
}

void Client::onErrorOccured()
{
    ui->log->append(tr("Error occured: %1").arg(m_socket->errorString()));
    ui->connectPushButton->setEnabled(true);
    ui->disconnectPushButton->setEnabled(false);
}

void Client::onReadyRead()
{
    if(!m_socket)
        return;
    m_data.append(m_socket->readAll());

    while(true){
        auto ETB_pos = m_data.indexOf(ETB);
        if(ETB_pos < 0)
            break;
        QString message = QString::fromUtf8(m_data.left(ETB_pos));

        /// Ako je poruka oblika "Username claim." klijent tada vraća server svoj username
        if( message == tr("Username claim.") ){
            QString message = ui->userLineEdit->text().trimmed();
            QByteArray poruka = message.toUtf8();
            poruka.append(ETB);
            m_socket->write(poruka);
            m_data.remove(0,ETB_pos+1);
            continue;
        }

        m_data.remove(0,ETB_pos+1);
        ui->log->setTextColor(QColor(Qt::darkGreen));
        ui->log->append(message);
        ui->log->setTextColor(QColor(Qt::black));
    }
}

void Client::onReturnPressed()
{
     QString message = ui->textLineEdit->text().trimmed();
     QByteArray poruka = message.toUtf8();
     poruka.append(ETB);
     m_socket->write(poruka);
     ui->log->setTextColor(QColor(Qt::blue));
     ui->log->append(QString("Me: %1").arg(message));
     ui->log->setTextColor(QColor(Qt::black));
     ui->textLineEdit->clear();
}

void Client::onDisconnectPushed()
{
    ui->log->append("Disconnecting.");
    m_socket->disconnectFromHost();
}

