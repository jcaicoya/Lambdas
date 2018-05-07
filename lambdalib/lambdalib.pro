QT += core
QT -= gui

CONFIG += c++14
CONFIG -= app_bundle

TARGET = lambda

TEMPLATE = lib

SOURCES += \
    application.cpp \
    functional.cpp

HEADERS += \
    application.h \
    functional.h
