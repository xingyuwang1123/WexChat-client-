QT       += core gui network ftp webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcutindialog.cpp \
    addfriendsdialog.cpp \
    addgroupdialog.cpp \
    applyitemform.cpp \
    centerbox.cpp \
    centerwindow.cpp \
    choosecutindialog.cpp \
    creategroupdialog.cpp \
    customwebenginepage.cpp \
    friendapplyform.cpp \
    friendsapplydialog.cpp \
    friendswindow.cpp \
    globle_param.cpp \
    groupapplydialog.cpp \
    groupapplyform.cpp \
    groupchatformform.cpp \
    groupinfoform.cpp \
    groupmemberdialog.cpp \
    groupwindow.cpp \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    messagechatform.cpp \
    messageitemform.cpp \
    messageshowform.cpp \
    messageshowitemform.cpp \
    messagewindow.cpp \
    navigator.cpp \
    newuserwindow.cpp \
    swebengineview.cpp \
    viedodialog.cpp \
    wexftp.cpp \
    wexnetwork.cpp

HEADERS += \
    WexConfig.h \
    addcutindialog.h \
    addfriendsdialog.h \
    addgroupdialog.h \
    applyitemform.h \
    centerbox.h \
    centerwindow.h \
    choosecutindialog.h \
    creategroupdialog.h \
    customwebenginepage.h \
    friendapplyform.h \
    friendsapplydialog.h \
    friendswindow.h \
    globle_param.h \
    groupapplydialog.h \
    groupapplyform.h \
    groupchatformform.h \
    groupinfoform.h \
    groupmemberdialog.h \
    groupwindow.h \
    loginwindow.h \
    mainwindow.h \
    messagechatform.h \
    messageitemform.h \
    messageshowform.h \
    messageshowitemform.h \
    messagewindow.h \
    navigator.h \
    newuserwindow.h \
    swebengineview.h \
    viedodialog.h \
    wexftp.h \
    wexnetwork.h

FORMS += \
    addcutindialog.ui \
    addfriendsdialog.ui \
    addgroupdialog.ui \
    applyitemform.ui \
    centerbox.ui \
    centerwindow.ui \
    choosecutindialog.ui \
    creategroupdialog.ui \
    friendapplyform.ui \
    friendsapplydialog.ui \
    friendswindow.ui \
    groupapplydialog.ui \
    groupapplyform.ui \
    groupchatformform.ui \
    groupinfoform.ui \
    groupmemberdialog.ui \
    groupwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    messagechatform.ui \
    messageitemform.ui \
    messageshowform.ui \
    messageshowitemform.ui \
    messagewindow.ui \
    navigator.ui \
    newuserwindow.ui \
    viedodialog.ui

#CONFIG(debug, debug|release) {
#    LIBS += -L ./lib/ -lQt5Ftpd
#} else {
#    LIBS += -L ./lib/ -lQt5Ftp
#}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsrc.qrc
