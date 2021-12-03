QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data.cpp \
    databasemanager.cpp \
    insertdata.cpp \
    loginadmin.cpp \
    loginwindow.cpp \
    main.cpp \
    people.cpp \
    storage.cpp

HEADERS += \
    data.h \
    databasemanager.h \
    insertdata.h \
    loginadmin.h \
    loginwindow.h \
    people.h \
    storage.h

FORMS += \
    insertdata.ui \
    loginadmin.ui \
    loginwindow.ui \
    people.ui \
    storage.ui

win32:RC_FILE=iconaizer.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
    CONFIG(release, debug | release)
    {
      win32:QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
    }

DISTFILES +=
