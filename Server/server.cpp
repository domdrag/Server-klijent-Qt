#include "server.h"
#include "ui_server.h"

#include <QTcpServer>
#include <QTcpSocket>

#include <algorithm>
#include <QMessageBox>

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server), m_server(new QTcpServer(this))
{
    ui->setupUi(this);
    if(!m_server->listen(QHostAddress("127.0.0.1"), 9090)){
        ui->log->appendPlainText(m_server->errorString());
        ui->log->appendPlainText(tr("server error = %1").arg(m_server->serverError()));
        return;
    }

    connect(m_server, &QTcpServer::newConnection, this, &Server::onNewConnection);
    connect(ui->disconnectPushButton, &QPushButton::clicked, this, &Server::onDisconnectPushed);

}

Server::~Server()
{
    delete ui;
}

void Server::onNewConnection()
{
    while(m_server->hasPendingConnections()){
        QTcpSocket* socket = m_server->nextPendingConnection();

        QString message = tr("Username claim.");
        QByteArray poruka = message.toUtf8();
        poruka.append(ETB);
        socket->write(poruka);

        m_sockets.push_back(socket);
        ui->log->appendPlainText(QString("Ostvarena konekcija sa %1, port %2").arg(socket->peerAddress().toString(),
                                                                         QString::number(socket->peerPort())));

        connect(socket, &QTcpSocket::readyRead, this, [this, socket](){ onReadyRead(socket); });
        connect(socket, &QTcpSocket::disconnected, this, [this, socket](){ onDisconnected(socket); });
    }
    ui->disconnectPushButton->setEnabled(true);

}

void Server::onReadyRead(QTcpSocket* socket)
{
    if(!socket)
        return;

    auto find_user = usernames.find(socket);
    if( find_user == usernames.end() ){
        QByteArray buffer = socket->readAll();
        auto ETB_pos = buffer.indexOf(ETB);
        QString message = QString::fromUtf8(buffer.left(ETB_pos));

        /// ako je korisnik poslao prazan username, prekidamo konekciju
        if(ETB_pos == 0){
            socket->deleteLater();
            return;
        }

        /// ako vec imamo korisnika sa istim usernameom, takodjer prekidamo konekciju
        for(auto klijent : usernames){
            if( std::get<1>(klijent) == message ){
                socket->deleteLater();
                return;
            }
        }
        usernames[socket] = message;
        return;
    }

    QByteArray& buffer = m_data[socket];
    buffer.append(socket->readAll());

    while(true){
        auto ETB_pos = buffer.indexOf(ETB);
        if(ETB_pos < 0)
            break;
        QString message = usernames[socket] + ": " + QString::fromUtf8(buffer.left(ETB_pos));
        buffer.remove(0,ETB_pos+1);
        ui->log->appendPlainText(message);
        QByteArray poruka = message.toUtf8();
        poruka.append(ETB);
        for(QTcpSocket* klijent : m_sockets)
            if(klijent != socket && klijent->state() == QAbstractSocket::ConnectedState)
                klijent->write(poruka);
    }
}

void Server::onDisconnected(QTcpSocket* socket)
{
    if(!socket)
        return;
    auto it = std::find(m_sockets.begin(), m_sockets.end(), socket);

    for(QTcpSocket* klijent : m_sockets)
        if(klijent == socket)
            ui->log->appendPlainText(QString("Prekinuta konekcija sa %1, port %2").arg(klijent->peerAddress().toString(),
                                                                               QString::number(klijent->peerPort())));
    if(it != m_sockets.end())
        m_sockets.erase(it);
    if(m_sockets.empty()) ui->disconnectPushButton->setEnabled(false);

    auto it_d = m_data.find(socket);
    if( it_d != m_data.end() )
        m_data.erase(it_d);

    auto it_u = usernames.find(socket);
    if( it_u != usernames.end() )
        usernames.erase(it_u);
}

void Server::onDisconnectPushed()
{
    for(QTcpSocket* klijent : m_sockets){        
        auto it_d = m_data.find(klijent);
        if(it_d != m_data.end())
            m_data.erase(it_d);
        ui->log->appendPlainText(QString("Prekinuta konekcija sa %1, port %2").arg(klijent->peerAddress().toString(),
                                                                                   QString::number(klijent->peerPort())));
        klijent->deleteLater();
    }
    m_sockets.clear();
    ui->disconnectPushButton->setEnabled(false);
}

