QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TARGET = test

TEMPLATE = app

INCLUDEPATH += $$PWD/..

LIBS += -L"/home/jogechu/Workspaces/C++/QtProjects/build-lambdas-Desktop_Qt_5_9_3_GCC_64bit-Debug/lambdalib" -llambda

SOURCES += \ 
    tst_lambdas.cpp
