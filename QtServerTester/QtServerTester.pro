# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

QT += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console

HEADERS += \
   argparser.h \
   mainwindow.h \
   myserver.h \
   setip.h \
   utils.h

SOURCES += \
   argparser.cpp \
   main.cpp \
   mainwindow.cpp \
   myserver.cpp \
   setip.cpp \
   utils.cpp

FORMS += \
    mainwindow.ui \
    setip.ui

#DEFINES = 

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
