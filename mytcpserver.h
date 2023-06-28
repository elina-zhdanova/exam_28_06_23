#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include<QVector>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
    void SendtoClient(QString str );
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    //int server_status;
};
#endif // MYTCPSERVER_H







