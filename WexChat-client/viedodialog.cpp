#include "viedodialog.h"
#include "ui_viedodialog.h"
#include <QStackedLayout>
#include <QWebEngineSettings>
#include <QWebChannel>
#include <QWebEnginePage>
#include "customwebenginepage.h"

ViedoDialog::ViedoDialog(QWidget *parent, QString pass) :
    QDialog(parent),
    ui(new Ui::ViedoDialog)
{
    ui->setupUi(this);

    m_webView = new SWebEngineView(this);
    //qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "7777");
    m_webView->move(0, 39);
    m_webView->resize(640, 441);
    m_webView->setPage(new CustomWebEnginePage());
    //m_webView->
    m_webView->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    m_webView->settings()->setAttribute(QWebEngineSettings::AllowRunningInsecureContent, true);
    m_webView->settings()->setAttribute(QWebEngineSettings::ScreenCaptureEnabled, true);
    m_webView->setUrl(QUrl(pass));
    m_webView->show();
    //m_webView->page()->setLinkDelegationPolicy();
//    QWebChannel *channel = new QWebChannel(this);
//    channel->registerObject("bridge", (QObject*)bridge::instance());
//    m_webView->page()->setWebChannel(channel);
//    QStackedLayout* layout = new QStackedLayout(ui->frame);
//    ui->frame->setLayout(layout);
//    layout->addWidget(m_webView);
//    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
//        QString url = ui->lineEdit->text();

//        if (!url.isEmpty())
//        {
//            m_webView->setUrl(QUrl(url));
//        }
//    });
}

ViedoDialog::~ViedoDialog()
{
    delete ui;
}
