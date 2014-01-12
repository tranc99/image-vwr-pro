#-------------------------------------------------
#
# Project created by QtCreator 2014-01-11T11:41:54
#
#-------------------------------------------------


TARGET = trysfml


#DEFINES += SFML_STATIC


SOURCES += main.cpp

INCLUDEPATH += $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
INCLUDEPATH += C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
LIBS += $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib/sfml-system-s.lib \
    $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib/sfml-window-s.lib \
    $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib/sfml-graphics-s.lib \
    $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib/sfml-audio-s.lib \
    $$PWD/../../../../../env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib/sfml-network-s.lib


INCLUDEPATH += C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
DEPENDPATH += C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/include
CONFIG(release, debug|release): LIBS += -L/C:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib -lsfml-audio-s -lsfml-graphics-s -lsfml-network-s -lsfml-window-s -lsfml-system-s
CONFIG(debug, debug|release): LIBS += -LC:/env/SFML-2.1-windows-vc10-32bits/SFML-2.1/lib -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
