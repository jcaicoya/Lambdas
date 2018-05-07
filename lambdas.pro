QT += core
QT -= gui

TARGET = lambdas

TEMPLATE = subdirs

CONFIG += c++14

SUBDIRS = \
	lambdalib \
	test \

lambdalib.subdir = lambdalib
test.subdir = test

test.depends = lambdalib

DEFINES += QT_DEPRECATED_WARNINGS
 
