#include "customwebenginepage.h"

CustomWebEnginePage::CustomWebEnginePage(QObject *parent) : QWebEnginePage(parent)
{
    connect(this, &QWebEnginePage::featurePermissionRequested, this, [=](const QUrl &securityOrigin, QWebEnginePage::Feature feature){
        setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
    });

}

bool CustomWebEnginePage::certificateError(const QWebEngineCertificateError &certificateError) {
    return true;
}
