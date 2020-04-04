#include "wexftp.h"
#include "WexConfig.h"
#include "globle_param.h"
#include <QDebug>
#include <QFile>
#include <QApplication>
#include <QCryptographicHash>

WexFtp::WexFtp(QObject *parent) : QObject(parent)
{
    ftp = new QFtp(this);

    connect(this->ftp, &QFtp::commandStarted, this, [=](int id){
        qDebug()<< "wexftp:id "<< id<< " started";
    });
    connect(this->ftp, &QFtp::commandFinished, this, [=](int id, bool error){
        if (error == true) {
            qDebug()<<"wexftp:error occured in id"<< id;
            qDebug()<< ftp->errorString();
            //workingMap.find(id).value()->close();
        }
        else {
            qDebug()<< "wexftp:id "<< id<< "finished";
        }

        if (workingMap.contains(id)) {
            workingMap.find(id).value()->close();
            emit fileFinished(workingMap.find(id).value()->fileName());
            workingMap.remove(id);
        }
    });
    ftp->connectToHost(FTP_ADDRESS);
    ftp->login(FTP_NAME, FTP_PASS);
}

QString WexFtp::fetchFile(QString filename) {
    //先打开文件
    QCoreApplication *qapp = QApplication::instance();
    QString filepass = qapp->applicationDirPath();
    filepass.append(TEMPFILE_DIR);
    TEMPDIRPASS = filepass;
    filepass.append(filename);
    QFile *file = new QFile(filepass);

    if (file->exists()) {
       qDebug()<<"wexftp:文件存在, 覆写文件:"<<filename;
    }
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug()<<"wexftp:文件打开失败:"<<filename;
        return "";
    }
    int id = ftp->get(filename, (QIODevice *)file);
    workingMap.insert(id, file);
    return file->fileName();
}

QString WexFtp::uploadFile(QString filepass) {
    QFile *file = new QFile(filepass);
    if (!file->exists()) {
        qDebug()<<"wexftp:文件不存在，无法上传:"<<filepass;
        return "";
    }
    if (!file->open(QIODevice::ReadOnly)) {
        qDebug()<<"wexftp:文件打开失败:"<<filepass;
        return  "";
    }
    //获取文件md5
    QByteArray ba = QCryptographicHash::hash(file->readAll(), QCryptographicHash::Md5);
    QString md5 = QString(ba.data());
    //获取后缀名
    QStringList list = filepass.split('/');
    QString name = list.last();
    if (name.contains('.')) {
        QStringList list2 = name.split('.');
        md5.append('.');
        md5.append(list2.last());
    }

    int id = ftp->put((QIODevice *)file, md5);
    workingMap.insert(id, file);
    return md5;
}

WexFtp::~WexFtp() {
    ftp->close();
}

