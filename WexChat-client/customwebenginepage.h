#ifndef CUSTOMWEBENGINEPAGE_H
#define CUSTOMWEBENGINEPAGE_H

#include <QObject>
#include <QWebEnginePage>

class CustomWebEnginePage : public QWebEnginePage
{
    Q_OBJECT
public:
    explicit CustomWebEnginePage(QObject *parent = nullptr);

    virtual bool certificateError(const QWebEngineCertificateError &certificateError);

signals:

};

#endif // CUSTOMWEBENGINEPAGE_H
