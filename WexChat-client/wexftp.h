#ifndef WEXFTP_H
#define WEXFTP_H

#include <QObject>
#include <qftp.h>
#include <QMap>
#include <QFile>

class WexFtp : public QObject
{
    Q_OBJECT
public:
    explicit WexFtp(QObject *parent = nullptr);
    static WexFtp* get_instance(){
        if (m_instance_ptr2 == nullptr) {
            m_instance_ptr2 = new WexFtp();
        }
        return m_instance_ptr2;
    }
    QString fetchFile(QString filename);
    QString uploadFile(QString filepass);
    ~WexFtp();
private:
    WexFtp(WexFtp&) = delete;
    WexFtp& operator=(const WexFtp&)=delete;
    static WexFtp *m_instance_ptr2;
    QFtp *ftp;
    QMap<int, QFile*> workingMap;
signals:
    void fileFinished(QString filename);

};

#endif // WEXFTP_H
