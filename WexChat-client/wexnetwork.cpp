#include "wexnetwork.h"
#include "WexConfig.h"
#include <QIODevice>
#include <QDebug>
#include <QTimer>
 #pragma execution_character_set("utf-8")
WexNetwork::WexNetwork(QObject *parent) : QObject(parent)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, &QIODevice::readyRead, this, &WexNetwork::readMessage);
    void(QTcpSocket::*errorSlot)(QAbstractSocket::SocketError) = &QTcpSocket::error;
    connect(tcpSocket, errorSlot, this, &WexNetwork::displayError);
    newConnect();
    aliveCount = 0;
    //开始计时心跳包
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        tcpSocket->write("ALIVE \n");
        aliveCount++;
        if (aliveCount > 5) {
            emit linkOut();
            aliveCount = 0;
        }
    });
    //timer->start(20000);
}

void WexNetwork::newConnect() {
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(SERVER_ADDRESS, SERVER_PORT);
}

void WexNetwork::readMessage() {
//    QDataStream in(tcpSocket);
//    if (blockSize == 0)  //刚开始接受数据
//    {
//        in>>message;
//        qDebug()<<"start read:"<<message;
//    }
    QString header = tcpSocket->readLine();
    QString res = header.section(' ', 0, 0);
    if (res == "RES") {
        QString code = header.section(' ', 1, 1);
        QString length = header.section(' ', 3, 3);
        if (code == "00") {
            message = tcpSocket->read(length.toInt());
            emit dataArrive();
        }
        else
            emit packageError();
    }
    else if (res == "ALIVE") {
        aliveCount--;
    }
    else if (res == "BRO") {
        QString code = header.section(' ', 1, 1);
        QString length = header.section(' ', 3, 3);
        if (code.toInt() == MESSAGEARRIVE) {
            QByteArray message2 = tcpSocket->read(length.toInt());
            qDebug() << "message arrives" << " " <<message2;
            emit boardArrive(MESSAGEARRIVE, message2);
        }
    }
    else {
        qDebug()<<"bad network package!";
    }
    qDebug()<<header<<"     "<<message;
}

QString WexNetwork::fetchPMessage() {
    return QString(message);
}

void WexNetwork::sendPMessage(QString msg, QString method) {
    QString res = "REQ ";
    res.append(method);
    res.append(' ');
    res.append(PROTOCOL_NAME);
    res.append('/');
    res.append(PROTOCOL_VERSION);
    res.append(' ');
    QByteArray ttt = msg.toUtf8();
    res.append(QString::number(ttt.length()));
    res.append(" \n");
    res.append(msg);
    messageOut = res.toUtf8();
    //writeMessage();
    qint64 ret = 0;
    //int length = messageOut.length();
    ret = tcpSocket->write(messageOut, messageOut.length());
}

void WexNetwork::writeMessage() {
    qint64 ret = 0;
    //int length = messageOut.length();
    ret = tcpSocket->write(messageOut, messageOut.length());
}



void WexNetwork::displayError(QAbstractSocket::SocketError) {
    qDebug()<<tcpSocket->errorString();
    //reconnect to server
    disconnect();
    newConnect();
}

void WexNetwork::disconnect() {
    tcpSocket->disconnectFromHost();
}
