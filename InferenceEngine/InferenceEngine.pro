#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T17:38:47
#
#-------------------------------------------------
QT       -= gui

TARGET = InferenceEngine
TEMPLATE = lib
#TEMPLATE = app
CONFIG -=app_bundle
#CONFIG += console c++11
CONFIG +=staticlib

DEFINES += INFERENCEENGINE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += inferencekernel.cpp \
    workspace.cpp \
    main.cpp

HEADERS += inferencekernel.h\
        inferenceengine_global.h \
    workspace.h

INCLUDEPATH += "/home/quique/Documents/Qt17/PROPCompilerBackup"
LIBS += "/home/quique/Documents/Qt17/build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/libPROPCompilerBackup.a"

unix {
    target.path = /usr/lib
    INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/ -lPROPCompilerBackup
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/ -lPROPCompilerBackup
else:unix: LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/ -lPROPCompilerBackup

INCLUDEPATH += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release
DEPENDPATH += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/libPROPCompilerBackup.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/libPROPCompilerBackup.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/PROPCompilerBackup.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/PROPCompilerBackup.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/libPROPCompilerBackup.a

RESOURCES += \
    resources.qrc

}
