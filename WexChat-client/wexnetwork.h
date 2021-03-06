#ifndef WEXNETWORK_H
#define WEXNETWORK_H
 #pragma execution_character_set("utf-8")
#include <QObject>
#include <QtNetwork>
#include <iostream>

class WexNetwork : public QObject
{
    Q_OBJECT
public:
    explicit WexNetwork(QObject *parent = nullptr);
    void newConnect();
    void disconnect();
    void sendPMessage(QString msg, QString method);
    QString fetchPMessage();
    enum boardType{
      MESSAGEARRIVE=0,ELSE=-1
    };
    static WexNetwork* get_instance(){
        if (m_instance_ptr == nullptr) {
            m_instance_ptr = new WexNetwork;
        }
        return m_instance_ptr;
    }
private:
    //单例模式
    WexNetwork(WexNetwork&) = delete;
    WexNetwork& operator=(const WexNetwork&)=delete;
    static WexNetwork* m_instance_ptr;
    QTcpSocket *tcpSocket;
    QByteArray message;
    QByteArray messageOut;
    quint16 blockSize;
    qint8 aliveCount;

    void readMessage();
    void writeMessage();
    void displayError(QAbstractSocket::SocketError);


signals:
    void dataArrive();
    void linkOut();
    void packageError();
    void boardArrive(boardType type, QByteArray data);
};

#endif // WEXNETWORK_H
