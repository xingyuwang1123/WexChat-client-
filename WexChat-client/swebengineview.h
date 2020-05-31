#ifndef SWEBENGINEVIEW_H
#define SWEBENGINEVIEW_H

#include <QWidget>
#include <QWebEngineView>
#include <QMouseEvent>

class SWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    explicit SWebEngineView(QWidget *parent = nullptr);

protected:
   // QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);

};

#endif // SWEBENGINEVIEW_H
