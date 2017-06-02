TEMPLATE = app

CONFIG = console

QMAKE_CXX = g++-6

QMAKE_CXXFLAGS += -std=c++14

LIBS += -ldl

SOURCES += main.cpp

OBJECTS_DIR = tmp

DESTDIR = ../bin
