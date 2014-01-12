#-------------------------------------------------
#
# Project created by QtCreator 2014-01-11T14:04:05
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        downloader.cpp \


HEADERS  += mainwindow.h\
            downloader.h

FORMS    += mainwindow.ui

#Add SFML Libraries
LIBS += -LC:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system-s
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH = C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
DEPENDPATH = C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include

OTHER_FILES += \
    water.jpg \
    ../build-Graphing-QT_4_8_Kit-Debug/data.txt

RESOURCES += \
    resource1.qrc

