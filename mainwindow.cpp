#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.01",33333);
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MainWindow::ReadyRead);
    connect(mTcpSocket, &QTcpSocket::disconnected,  mTcpSocket,&QTcpSocket::deleteLater);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadyRead()
{
    QDataStream in(mTcpSocket);
    QString str;
    in>> str;
    ui->textBrowser->append(str);
}

void MainWindow::SendServer(QString str)
{
    Data.clear();
    QDataStream out(&Data,QIODevice::WriteOnly);
    out<<str;
    mTcpSocket->write(Data);
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_clicked()
{
 SendServer(ui->lineEdit->text());
}

