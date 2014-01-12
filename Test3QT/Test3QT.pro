TEMPLATE = app
CONFIG += console

SOURCES += main.cpp
#DEFINES += SFML_STATIC



LIBS += -LC:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system-s
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH = C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
DEPENDPATH = C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
