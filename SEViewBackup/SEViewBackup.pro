#-------------------------------------------------
#
# Project created by QtCreator 2017-11-06T13:45:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEViewBackup
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        seview.cpp \
    subjectWidget.cpp \
    coverWidget.cpp \
    conclusionsWidget.cpp

HEADERS  += seview.h \
    conclusionsWidget.h \
    coverWidget.h \
    subjectWidget.h

FORMS    += seview.ui

RESOURCES += \
    seresources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/release/ -lInferenceEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/ -lInferenceEngine
else:unix:!macx: LIBS += -L$$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/ -lInferenceEngine

LIBS+= "/home/quique/Documents/Qt17/build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/libPROPCompilerBackup.a"
INCLUDEPATH+= "/home/quique/Documents/Qt17/PROPCompilerBackup"

LIBS+= "/home/quique/Documents/Qt17/build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/libInferenceEngine.a"
INCLUDEPATH+= "/home/quique/Documents/Qt17/InferenceEngine"


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/release/libInferenceEngine.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/libInferenceEngine.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/release/InferenceEngine.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/InferenceEngine.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../build-InferenceEngine-Desktop_Qt_5_8_0_GCC_64bit-Release/libInferenceEngine.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/ -lPROPCompilerBackup
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/ -lPROPCompilerBackup
else:unix:!macx: LIBS += -L$$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/ -lPROPCompilerBackup

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/libPROPCompilerBackup.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/libPROPCompilerBackup.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/release/PROPCompilerBackup.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/debug/PROPCompilerBackup.lib
else:unix:!macx: PRE_TARGETDEPS += $$PWD/../build-PROPCompilerBackup-Desktop_Qt_5_8_0_GCC_64bit-Release/libPROPCompilerBackup.a
