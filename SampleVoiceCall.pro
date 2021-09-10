QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS_RELEASE -= -Zc:strictStrings



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += "C:\Users\Puneet\Desktop\PJSIP_VS15\pjproject-2.10\pjsip\include"
INCLUDEPATH += "C:\Users\Puneet\Desktop\PJSIP_VS15\pjproject-2.10\pjlib\include"
INCLUDEPATH += "C:\Users\Puneet\Desktop\PJSIP_VS15\pjproject-2.10\pjlib-util\include"
INCLUDEPATH += "C:\Users\Puneet\Desktop\PJSIP_VS15\pjproject-2.10\pjmedia\include"
INCLUDEPATH += "C:\Users\Puneet\Desktop\PJSIP_VS15\pjproject-2.10\pjnath\include"

LIBS += -lWs2_32 -lOle32 -lwsock32  -ldsound

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    util.h

FORMS += \
    mainwindow.ui



win32: LIBS += -L$$PWD/lib/ -llibbaseclasses-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibg7221codec-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibgsmcodec-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibilbccodec-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibmilenage-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibpjproject-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibresample-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibspeex-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibsrtp-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibwebrtc-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -llibyuv-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjlib-util-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjlib-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjmedia-audiodev-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjmedia-codec-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjmedia-videodev-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjmedia-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjnath-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjsip-core-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjsip-simple-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjsip-ua-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjsua2-lib-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

win32: LIBS += -L$$PWD/lib/ -lpjsua-lib-x86_64-x64-vc14-Debug

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib
