QT = core

CONFIG += c++17 cmdline

SOURCES += \
#        1.cpp \
#        2a.cpp \
#        2b.cpp \
#        2c.cpp \
        Comunicacion.cpp \
        propuesto1.cpp

HEADERS += \
    Comunicacion.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target